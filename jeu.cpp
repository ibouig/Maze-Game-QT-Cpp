#include "jeu.h"
#include"board.h"
#include<QMainWindow>
#include<QKeyEvent>
#include"mylabel.h"

jeu::jeu(int choix)
{
    cas=false;
    this->setFixedSize(750,650);
    setWindowTitle("play game");
    choice=choix;
  b = new Board(this,choix) ;
  Ci=0;
  Cj=0;
  setWindowIcon(QIcon("images/win_icon.jpg"));

  A_Plan=new QLabel(this);
  A_Plan->setObjectName(QStringLiteral("Arriere_Plan"));
  A_Plan->setFixedSize(750,650);
  A_Plan->setPixmap(QPixmap("images/espace_jeux.png"));
  A_Plan->lower();

  time_elapsed = new QTime();  //Pour calculer le temps passer dans le jeu
  timer=new QTimer();
  time_elapsed->start();
  timer->start();

  time_label=new QLabel(this);
  time_label->move(635,70);
  time_label->setStyleSheet("background-color:white;padding-left:20px;");
  time_label->setFont(QFont("digital-7",20,2,false));

  quitter=new QPushButton(this);
  quitter->move(630,340);
  quitter->setText("Quitter");
  quitter->setFont(QFont("Replay",14,2,false));
  quitter->setToolTip("Quitter l'application");
  quitter->setCursor(Qt::PointingHandCursor);

  rejouer = new QPushButton(this);
  rejouer->move(630,260);
  rejouer->setText("Rejouer");
  rejouer->setFont(QFont("Replay",14,2,false));
  rejouer->setToolTip("voir la solution");
  rejouer->setCursor(Qt::PointingHandCursor);
  QObject::connect(rejouer,SIGNAL(clicked()),this,SLOT(rejoue()));
  QObject::connect(timer,SIGNAL(timeout()),this,SLOT(update_time()));
  solution = new QPushButton(this);
  solution->move(630,300);
  solution->setText("Resoudre");
  solution->setFont(QFont("Replay",14,2,false));
  solution->setToolTip("voir la solution");
  solution->setCursor(Qt::PointingHandCursor);
  QObject::connect(solution,SIGNAL(clicked()),this,SLOT(resolve()));
  QObject::connect(quitter,SIGNAL(clicked()),this,SLOT(close()));
  QObject::connect(this,SIGNAL(fin_s()),this,SLOT(fin()));
  quitter->setFocusPolicy(Qt::NoFocus);
  rejouer->setFocusPolicy(Qt::NoFocus);
  solution->setFocusPolicy(Qt::NoFocus);
}


void jeu::keyReleaseEvent(QKeyEvent* event) {
    if (cas)
           event->ignore();
    else{

        QPixmap pixmap;
        switch (choice)
        {
            case 0: pixmap.load("images/icon_easy.png");break;
            case 1: pixmap.load("images/icon_medium.png");break;
            case 2: pixmap.load("images/icon_hard.png");break;
        }
if ((event->key() == Qt::Key_Right)&&(b->labeltab[Ci][Cj].BR==0))
 {

                  b->labeltab[Ci][Cj].setText(" ");
                  b->labeltab[Ci][++Cj].setPixmap(pixmap);
                  b->labeltab[Ci][Cj].setAlignment(Qt::AlignCenter);
            }
if ((event->key() == Qt::Key_Left)&&(b->labeltab[Ci][Cj].BL==0)){
                  b->labeltab[Ci][Cj].setText(" ");
                  b->labeltab[Ci][--Cj].setPixmap(pixmap);
                  b->labeltab[Ci][Cj].setAlignment(Qt::AlignCenter);
            }
if ((event->key() == Qt::Key_Down)&&(b->labeltab[Ci][Cj].BB==0))
{
                  b->labeltab[Ci][Cj].setText(" ");
                  b->labeltab[++Ci][Cj].setPixmap(pixmap);
                  b->labeltab[Ci][Cj].setAlignment(Qt::AlignCenter);
             }
if ((event->key() == Qt::Key_Up)&&(b->labeltab[Ci][Cj].BT==0))
{
                  b->labeltab[Ci][Cj].setText(" ");
                  b->labeltab[--Ci][Cj].setPixmap(pixmap);
                  b->labeltab[Ci][Cj].setAlignment(Qt::AlignCenter);

}
if((Ci==b->t-1)&&(Cj==b->t-1)){
        emit fin_s();
    }
    }
}

void jeu::update_time(){
    int secs = time_elapsed->elapsed() / 1000;
    int mins = (secs / 60) % 60;
    secs = secs % 60;
    time_label->setText(QString("%1:%2").arg(mins, 2, 10, QLatin1Char('0')).arg(secs, 2, 10, QLatin1Char('0')) );
}

jeu::~jeu()
{
delete b;
}
void jeu::resolve()
{
       solution->setEnabled(false);
       cas=true;
       b->drawSolution(Ci,Cj);
       timer->stop();

}



