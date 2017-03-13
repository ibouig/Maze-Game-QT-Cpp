#include "menu.h"
#include <QUrl>
#include "bits/stdc++.h"
#include <QDebug>
#include <QString>
#include <QFile>
#include <QMessageBox>

using namespace std;
int menu::is_muted=1;


menu::menu(QWidget *parent) : QWidget(parent)
{

    this->setFixedSize(700,560);
    this->setWindowIcon(QIcon(":/img/menu_icon.png"));
    this->setWindowTitle("The Maze 1.0");
    //set menu background
    QLabel *Menu_photo = new QLabel(this);
    Menu_photo->setGeometry(0,0,700,560);
    QPixmap *PixMenu = new QPixmap(":/img/menu.png");
    Menu_photo->setPixmap(*PixMenu);

    //music button
    music_control = new QPushButton(this);
    music_control->setGeometry(630,500,50,40);
    music_control->setCursor(Qt::PointingHandCursor);
    music_control->setIconSize(QSize(50,40));
    music_control->raise();
    QObject::connect(music_control,SIGNAL(clicked(bool)),this,SLOT(menu_sound()));

    //set background music
    music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/audio/bg_sound.mp3"));
    if(is_muted == 1)
    {
        music->play();
        music_control->setIcon(QIcon(":/img/on.png"));
    }
    else
    {
        music_control->setIcon(QIcon(":/img/off.png"));
    }



    //Main Buttons
    play_button = new QPushButton(this);
    play_button->setGeometry(51,200,150,40);
    play_button->setCursor(Qt::PointingHandCursor);
    play_button->setIcon(QIcon(":/img/play2.png"));
    play_button->setIconSize(QSize(150,40));
    play_button->raise();
    QObject::connect(play_button,SIGNAL(clicked(bool)),this,SLOT(new_game()));

    howTo_button = new QPushButton(this);
    howTo_button->setGeometry(50,270,150,40);
    howTo_button->setCursor(Qt::PointingHandCursor);
    howTo_button->setIcon(QIcon(":/img/help2.png"));
    howTo_button->setIconSize(QSize(150,40));
    howTo_button->raise();
    QObject::connect(howTo_button,SIGNAL(clicked(bool)),this,SLOT(help()));

    about_button = new QPushButton(this);
    about_button->setGeometry(50,340,150,40);
    about_button->setCursor(Qt::PointingHandCursor);
    about_button->setIcon(QIcon(":/img/credits2.png"));
    about_button->setIconSize(QSize(150,40));
    about_button->raise();
    QObject::connect(about_button,SIGNAL(clicked(bool)),this,SLOT(about()));

    score_list = new QPushButton(this);
    score_list->setGeometry(50,410,150,40);
    score_list->setCursor(Qt::PointingHandCursor);
    score_list->setIcon(QIcon(":/img/topScore.png"));
    score_list->setIconSize(QSize(150,40));
    score_list->raise();
    QObject::connect(score_list,SIGNAL(clicked(bool)),this,SLOT(score()));

    exit_button = new QPushButton(this);
    exit_button->setGeometry(50,480,150,40);
    exit_button->setCursor(Qt::PointingHandCursor);
    exit_button->setIcon(QIcon(":/img/exit2.png"));
    exit_button->setIconSize(QSize(150,40));
    exit_button->raise();
    QObject::connect(exit_button,SIGNAL(clicked(bool)),qApp,SLOT(quit()));

    //level choose Combox
    QLabel *lvl = new QLabel(this);
    lvl->setGeometry(385,260,184,30);
    lvl->setText("Levels:");
    QPixmap *lvl_pic = new QPixmap(":/img/level.png");
    lvl->setPixmap(*lvl_pic);
    lvl->raise();

    levels = new QComboBox(this);
    levels->setGeometry(390,305,180,22);
    levels->addItem("Easy");
    levels->addItem("Medium");
    levels->addItem("Hard");
    levels->setStyleSheet("background: #FFFFFF;");
    levels->raise();

    //avatar choose Combox
    QLabel *av = new QLabel(this);
    av->setGeometry(385,365,184,30);
    av->setText("Levels:");
    QPixmap *av_pic = new QPixmap(":/img/avatars.png");
    av->setPixmap(*av_pic);
    av->raise();

    avatar = new QComboBox(this);
    avatar->setGeometry(390,405,180,22);
    avatar->addItem("Mario");
    avatar->addItem("Circle");
    avatar->addItem("Bee");
    avatar->setStyleSheet("background: #FFFFFF;");
    avatar->raise();



}

void menu::about()
{
    about_page = new QWidget();
    about_page->setFixedSize(320,500);
    about_page->setWindowTitle("Credits");
    about_page->setWindowIcon(QIcon(":/img/menu_icon.png"));
    about_page->setStyleSheet("QWidget{background-image: url(:/img/about_page.png)}");
    about_page->show();
}

void menu::help()
{
    help_page = new QWidget();
    help_page->setFixedSize(320,500);
    help_page->setWindowTitle("How To Play ?");
    help_page->setWindowIcon(QIcon(":/img/menu_icon.png"));
    help_page->setStyleSheet("QWidget{background-image: url(:/img/help_page.png)}");
    help_page->show();
}
void menu::new_game()
{
    this->close();
    music->stop();
    game * g = new game(levels->currentIndex(),avatar->currentIndex());
    g->show();
}

void menu::menu_sound()
{
    if(is_muted == 1 && music->state() == QMediaPlayer::PlayingState)
    {
        is_muted=0;
        //music->setPosition(0);
        music->pause();
        music_control->setIcon(QIcon(":/img/off.png"));
    }
    else if(is_muted == 0 || music->state() == QMediaPlayer::StoppedState)
    {
        is_muted=1;
        music->play();
        music_control->setIcon(QIcon(":/img/on.png"));
    }
}

void menu:: score()
{
    QFile file("D:/Maze_score.txt");
        QString r ;
        r="";
        int k=1 ;

      file.open(QIODevice::ReadOnly | QIODevice::Text);

            QTextStream flux(&file);
            while(!flux.atEnd() && k<=5)
            {
                QString temp = flux.readLine();
                r+="Score";
                r+=QString::number(k);
                r+=" : ";
                if(temp.toInt()>9)
                   r+=temp;
               else
               {
                   r+="0"+temp;
               }
                r+="\n";
                k++ ;
            }
            if(k<=5)
            {
              for(int i=k;i<=5;i++)
              {
               r+="Score";
               r+=QString::number(i);
               r+=" : 00\n" ;
              }
            }


            file.close();


    score_page = new QWidget();
    score_page->setFixedSize(320,500);
    score_page->setWindowTitle("ScoreBoard");
    score_page->setWindowIcon(QIcon(":/img/menu_icon.png"));
    QLabel *bg = new QLabel(score_page);
    bg->setGeometry(0,0,320,500);
    QPixmap *bgP = new QPixmap(":/img/scoreboard.png");
    bg->setPixmap(*bgP);
    bg->raise();
    QLabel *board =  new QLabel(score_page);
    board->setGeometry(0,250,320,250);
    QString text=r ;
    board->setText(text);
    board->setAlignment(Qt::AlignCenter);
    board->setFont(QFont("Elephant",20,5,false));
    board->setStyleSheet("QLabel {color : white; }");
    board->raise();
    score_page->show();
}

menu::~menu()
{

}
