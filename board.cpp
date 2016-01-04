#include<QGridLayout>
#include<QLabel>
#include"jeu.h"
#include "board.h"
#include <QKeyEvent>
#include"mylabel.h"




Board::Board(QMainWindow* parent,int choix)
{
    this->resize(600, 600);
    gridLayoutWidget = new QWidget(parent);
    gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
    gridLayoutWidget->setGeometry(QRect(10, 10, 600, 600));
    gridLayout = new QGridLayout(gridLayoutWidget);
    gridLayout->setSpacing(0);
    gridLayout->setObjectName(QStringLiteral("gridLayout"));
    gridLayout->setContentsMargins(0, 0, 0, 0);
    gridLayoutWidget->setStyleSheet("background-color: white");

    switch (choix)
    {
        case easy: t=15;m=new SideW(t,t);break;
        case medium:t=30;m=new Prim(t,t);break;
        case hard:t=50;m=new Gbtree(t,t);break;
    }
    labeltab=new mylabel * [t];
    for (int i=0;i<t;i++) labeltab[i]=new mylabel [t];
    for (int i=0;i<t;i++)
        {
            for (int j=0;j<t;j++)
                {
                    gridLayout-> addWidget(&labeltab[i][j],i,j);
                    labeltab[i][j].setIndent(0);
                    labeltab[i][j].setFrameShape(QFrame::NoFrame);

                }
        }
    this->show();



}
void Board::show(){

        for(int i=0; i<t; i++)
        {
            for(int j=0; j<t; j++)
            {

                switch ( m->gettab()[i][j] )
                {
                case '7' : labeltab[i][j].setStyleSheet("border-top: 1px solid white;\n""border-bottom: 1px solid white;\n""border-left: 1px solid white;\n""border-right: 1px solid black;\n");
                             labeltab[i][j].BR=1;
                                        break;
                case '>' : labeltab[i][j].setStyleSheet("border-top: 1px solid black;\n""border-bottom: 1px solid white;\n""border-left: 1px solid white;\n""border-right: 1px solid white;\n");
                            labeltab[i][j].BT=1;
                                        break;
                case ';' : labeltab[i][j].setStyleSheet("border-top: 1px solid white;\n""border-bottom: 1px solid black;\n""border-left: 1px solid white;\n""border-right: 1px solid white;\n");
                            labeltab[i][j].BB=1;
                                        break;
                case '=' : labeltab[i][j].setStyleSheet("border-top: 1px solid white;\n""border-bottom: 1px solid white;\n""border-left: 1px solid black;\n""border-right: 1px solid white;\n");
                            labeltab[i][j].BL=1;
                                        break;
                case '6' : labeltab[i][j].setStyleSheet("border-top: 1px solid black;\n""border-bottom: 1px solid white;\n""border-left: 1px solid white;\n""border-right: 1px solid black;\n");
                                      labeltab[i][j].BT=1;
                                      labeltab[i][j].BR=1;
                                        break;
                case '3' : labeltab[i][j].setStyleSheet("border-top: 1px solid white;\n""border-bottom: 1px solid black;\n""border-left: 1px solid white;\n""border-right: 1px solid black;\n");
                                        labeltab[i][j].BR=1;
                                        labeltab[i][j].BB=1;
                                        break;
                case '5' : labeltab[i][j].setStyleSheet("border-top: 1px solid white;\n""border-bottom: 1px solid white;\n""border-left: 1px solid black;\n""border-right: 1px solid black;\n");
                                      labeltab[i][j].BR=1;
                                      labeltab[i][j].BL=1;
                                        break;
                case ':' : labeltab[i][j].setStyleSheet("border-top: 1px solid black;\n""border-bottom: 1px solid black;\n""border-left: 1px solid white;\n""border-right: 1px solid white;\n");
                                        labeltab[i][j].BT=1;
                                        labeltab[i][j].BB=1;
                                        break;
                case '<' : labeltab[i][j].setStyleSheet("border-top: 1px solid black;\n""border-bottom: 1px solid white;\n""border-left: 1px solid black;\n""border-right: 1px solid white;\n");
                                       labeltab[i][j].BT=1;
                                       labeltab[i][j].BL=1;
                                        break;
                case '9' : labeltab[i][j].setStyleSheet("border-top: 1px solid white;\n""border-bottom: 1px solid black;\n""border-left: 1px solid black;\n""border-right: 1px solid white;\n");
                                       labeltab[i][j].BB=1;
                                       labeltab[i][j].BL=1;
                                        break;
                case '2' : labeltab[i][j].setStyleSheet("border-top: 1px solid black;\n""border-bottom: 1px solid black;\n""border-left: 1px solid white;\n""border-right: 1px solid black;\n");
                                        labeltab[i][j].BT=1;
                                        labeltab[i][j].BR=1;
                                        labeltab[i][j].BB=1;
                                        break;
                case '4' : labeltab[i][j].setStyleSheet("border-top: 1px solid black;\n""border-bottom: 1px solid white;\n""border-left: 1px solid black;\n""border-right: 1px solid black;\n");
                                       labeltab[i][j].BT=1;
                                       labeltab[i][j].BR=1;
                                       labeltab[i][j].BL=1;
                                        break;
                case '1' : labeltab[i][j].setStyleSheet("border-top: 1px solid white;\n""border-bottom: 1px solid black;\n""border-left: 1px solid black;\n""border-right: 1px solid black;\n");
                                        labeltab[i][j].BB=1;
                                        labeltab[i][j].BR=1;
                                        labeltab[i][j].BL=1;
                                        break;
                case '8' : labeltab[i][j].setStyleSheet("border-top: 1px solid black;\n""border-bottom: 1px solid black;\n""border-left: 1px solid black;\n""border-right: 1px solid white;\n");
                                        labeltab[i][j].BT=1;
                                        labeltab[i][j].BB=1;
                                        labeltab[i][j].BL=1;
                                        break;
                case '?' : labeltab[i][j].setStyleSheet("border-top: 1px solid white;\n""border-bottom: 1px solid white;\n""border-left: 1px solid white;\n""border-right: 1px solid white;\n");
                                        labeltab[i][j].BT=0;
                                        labeltab[i][j].BR=0;
                                        labeltab[i][j].BL=0;
                                        labeltab[i][j].BB=0;
                                        break;

                }

            }

        }
        QPixmap pixmap1;
        QPixmap pixmap;
        switch (t)
        {
        case 15: pixmap.load("images/icon_easy.png");pixmap1.load("images/iconArrive_easy.png");break;
        case 30: pixmap.load("images/icon_medium.png");pixmap1.load("images/iconArrive_medium.png");break;
        case 50: pixmap.load("images/icon_hard.png");pixmap1.load("images/iconArrive_medium.png");break;}
        labeltab[0][0].setPixmap(pixmap);
        labeltab[0][0].setAlignment(Qt::AlignCenter);
        labeltab[t-1][t-1].setPixmap(pixmap1);
        labeltab[t-1][t-1].setAlignment(Qt::AlignCenter);

}

void Board::drawSolution(int Ci,int Cj)
{
    int c=Ci,d=Cj;
    m->Backtracker(c,d,t-1,t-1);


                int y,x;
                 while(m->P!=NULL)
                    {
                        m->sommet(m->P,y,x);
                        m->depiler(m->P);
                        QPixmap pixmap2;
                        pixmap2.load("images/icon_sol.png");
                        labeltab[y][x].setPixmap(pixmap2);
                        labeltab[y][x].setAlignment(Qt::AlignCenter);
                    }
                 QPixmap pixmap1;
                 QPixmap pixmap;
                 switch (t)
                 {
                 case 15: pixmap.load("images/icon_easy.png");pixmap1.load("images/iconArrive_easy.png");break;
                 case 30: pixmap.load("images/icon_medium.png");pixmap1.load("images/iconArrive_medium.png");break;
                 case 50: pixmap.load("images/icon_hard.png");pixmap1.load("images/iconArrive_medium.png");break;}
                 labeltab[Ci][Cj].setPixmap(pixmap);
                 labeltab[Ci][Cj].setAlignment(Qt::AlignCenter);
                 labeltab[t-1][t-1].setPixmap(pixmap1);
                 labeltab[t-1][t-1].setAlignment(Qt::AlignCenter);

}
Board::~Board()
{

}

void Board::newGame()
{
}
