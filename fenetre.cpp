#include "fenetre.h"

fenetre::fenetre(int a=380,int b=526) :QWidget()
{
    setFixedSize(a,b);
    setWindowTitle("maze menu");
    QLabel  *label  = new QLabel(this);
    QPixmap *pixmap = new QPixmap("images/intro_jeu.png");
    label->setPixmap(*pixmap);
    label->raise();
    setWindowIcon(QIcon("images/win_icon.jpg"));

    play= new QPushButton(this);
    play->setText("PLAY");
    play->setFont(QFont("Replay",24,1,false));
    play->setGeometry(QRect(12, 354, 357, 33));
    play->setToolTip("JOUER");
    play->setCursor(Qt::PointingHandCursor);
    play->setStyleSheet("border-radius:9px;background: #FFFFFF;color:#28375a");
    play ->setIcon( QIcon("images/play.png"));
    play->raise();
   QObject::connect(play,SIGNAL(clicked()),this, SLOT(interm()));

    instruction= new QPushButton(this);
    instruction->setText("instructions");
    instruction->setFont(QFont("replay",24,1,false));
    instruction->setGeometry(QRect(12, 397, 357, 33));
    instruction->setIcon( QIcon("images/resume.png"));
    instruction->setCursor(Qt::PointingHandCursor);
    instruction->setStyleSheet("border-radius:9px;background: #FFFFFF;color:#28375a");
    QObject::connect(instruction,SIGNAL(clicked()),this,SLOT(instruc()));

    about= new QPushButton(this);
    about->setText("about us");
    about->setStyleSheet("border-radius:9px;background: #FFFFFF;color:#28375a");
    about->setFont(QFont("replay",24,1,false));
    about->setGeometry(QRect(12, 439, 357, 33));
    QObject::connect(about,SIGNAL(clicked()),this,SLOT(aboutt()));


    exit= new QPushButton(this);
    exit->setText("exit");
    exit->setFont(QFont("replay",24,1,false));
    exit->setStyleSheet("border-radius:9px;background: #FFFFFF;color:#28375a");
    exit->setGeometry(QRect(12, 479, 357, 33));
    exit->setIcon( QIcon("images/quit.png"));
    QObject::connect(exit, SIGNAL(clicked()), qApp, SLOT(quit()));


    choose =new QLabel(this);
    choose->setFont(QFont("replay",14,2,false));
    choose->setGeometry(QRect(50,323, 248, 23));
    choose->setStyleSheet("color:#FFFFFF");
    choose->setText("choose your level :");

    lev=new QComboBox(this);//liste de choix de niveau
    lev->setGeometry(QRect(190, 323, 150, 23));
    lev->setFont(QFont("replay",12,2,false));
    lev->addItem("easy");
    lev->addItem("medium");
    lev->addItem("hard");
    lev->setStyleSheet("background: #FFFFFF;");
    QObject::connect(lev,SIGNAL(currentIndexChanged(int)),this, SLOT(backgr() ));

    inst =new QWidget();
    inst->setFixedSize(380,526);
    inst->setWindowTitle("instructions");
    inst->setWindowIcon(QIcon("images/win_icon.jpg"));


    QString styleSheet_inst("QWidget{background-image:url(images/Instruction.png)}");
    inst->setStyleSheet(styleSheet_inst);


    ab =new QWidget();
    ab->setFixedSize(380,526);
    ab->setWindowTitle("about us");
    QString styleSheet("QWidget{background-image:url(images/credits_jeu.png)}");
    ab->setStyleSheet(styleSheet);
    ab->setWindowIcon(QIcon("images/win_icon.jpg"));
}
void jeu::rejoue()
{

    this-> close();//cacher fenetre du jeu
    this->~jeu();
    this->Ci=0;
    this->Cj=0;
    fenetre *fenn= new fenetre(380,526);//afficher fenetre
    fenn->show();
}
 void fenetre::backgr()
{
}
 void fenetre::interm()
 {
     hide();
     jeu * w=new jeu(lev->currentIndex());
     w->show();

 }
 void fenetre::instruc()
 {
     inst->show();

 }
 void fenetre::aboutt()
 {
    ab->show();
 }

 void jeu::fin()
 {
     QMessageBox M;
     timer->stop();
     int reponse= M.question(this, "congratulations", "you won the game . play again ?",QMessageBox::Yes | QMessageBox::No);
     if (reponse == QMessageBox::Yes)
     {
         M.close();
         close();
         fenetre *fenn= new fenetre(380,526);//afficher fenetre
         fenn->show();
     }
     else if (reponse == QMessageBox::No)
     {
         M.close();
         close();
     }
 }
