#include "mainwindow.h"
#include"maze.h"

void MainWindow::show(Maze m, QLabel ** labeltab)
{

        for(int i=0; i<m.wdth; i++)
        {
            for(int j=0; j<m.wdth; j++)
            {

                switch ( m.cells[i][j] )
                {
                        case '7' : labeltab[i][j].setStyleSheet("border-top: 1px solid white;\n""border-bottom: 1px solid white;\n""border-left: 1px solid white;\n""border-right: 1px solid black;\n");
                                                break;
                        case '>' : labeltab[i][j].setStyleSheet("border-top: 1px solid black;\n""border-bottom: 1px solid white;\n""border-left: 1px solid white;\n""border-right: 1px solid white;\n");
                                                break;
                        case ';' : labeltab[i][j].setStyleSheet("border-top: 1px solid white;\n""border-bottom: 1px solid black;\n""border-left: 1px solid white;\n""border-right: 1px solid white;\n");
                                                break;
                        case '=' : labeltab[i][j].setStyleSheet("border-top: 1px solid white;\n""border-bottom: 1px solid white;\n""border-left: 1px solid black;\n""border-right: 1px solid white;\n");
                                                break;
                        case '6' : labeltab[i][j].setStyleSheet("border-top: 1px solid black;\n""border-bottom: 1px solid white;\n""border-left: 1px solid white;\n""border-right: 1px solid black;\n");
                                                break;
                        case '3' : labeltab[i][j].setStyleSheet("border-top: 1px solid white;\n""border-bottom: 1px solid black;\n""border-left: 1px solid white;\n""border-right: 1px solid black;\n");
                                                break;
                        case '5' : labeltab[i][j].setStyleSheet("border-top: 1px solid white;\n""border-bottom: 1px solid white;\n""border-left: 1px solid black;\n""border-right: 1px solid black;\n");
                                                break;
                        case ':' : labeltab[i][j].setStyleSheet("border-top: 1px solid black;\n""border-bottom: 1px solid black;\n""border-left: 1px solid white;\n""border-right: 1px solid white;\n");
                                                break;
                        case '<' : labeltab[i][j].setStyleSheet("border-top: 1px solid black;\n""border-bottom: 1px solid white;\n""border-left: 1px solid black;\n""border-right: 1px solid white;\n");
                                                break;
                        case '9' : labeltab[i][j].setStyleSheet("border-top: 1px solid white;\n""border-bottom: 1px solid black;\n""border-left: 1px solid black;\n""border-right: 1px solid white;\n");
                                                break;
                        case '2' : labeltab[i][j].setStyleSheet("border-top: 1px solid black;\n""border-bottom: 1px solid black;\n""border-left: 1px solid white;\n""border-right: 1px solid black;\n");
                                                break;
                        case '4' : labeltab[i][j].setStyleSheet("border-top: 1px solid black;\n""border-bottom: 1px solid white;\n""border-left: 1px solid black;\n""border-right: 1px solid black;\n");
                                                break;
                        case '1' : labeltab[i][j].setStyleSheet("border-top: 1px solid white;\n""border-bottom: 1px solid black;\n""border-left: 1px solid black;\n""border-right: 1px solid black;\n");
                                                break;
                        case '8' : labeltab[i][j].setStyleSheet("border-top: 1px solid black;\n""border-bottom: 1px solid black;\n""border-left: 1px solid black;\n""border-right: 1px solid white;\n");
                                                break;
                        case '?' : labeltab[i][j].setStyleSheet("border-top: 1px solid white;\n""border-bottom: 1px solid white;\n""border-left: 1px solid white;\n""border-right: 1px solid white;\n");
                                                break;
                        //default : labeltab[i][j].setStyleSheet("border-top: 1px solid black;\n""border-bottom: 1px solid black;\n""border-left: 1px solid black;\n""border-right: 1px solid black;\n");

                }

            }

        }
            pixmap.load("icon.png");
            labeltab[0][0].setPixmap(pixmap);
            labeltab[0][0].setAlignment(Qt::AlignCenter);
}
MainWindow::MainWindow(int t)
{
    labeltab=new QLabel*[t];
    for (int i=0;i<t;i++)
        labeltab[i]=new QLabel[t];
    this->resize(800, 600);
    gridLayoutWidget = new QWidget(this);
    gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
    gridLayoutWidget->setGeometry(QRect(29, 30, 500, 500));
    gridLayout = new QGridLayout(gridLayoutWidget);
    gridLayout->setSpacing(0);
    gridLayout->setObjectName(QStringLiteral("gridLayout"));
    gridLayout->setContentsMargins(0, 0, 0, 0);

    for (int i=0;i<t;i++)
        {
            for (int j=0;j<t;j++)
                {
                    gridLayout-> addWidget(&labeltab[i][j],i,j);
                    labeltab[i][j].setIndent(0);
                    labeltab[i][j].setFrameShape(QFrame::NoFrame);

                }
        }
}
MainWindow::~MainWindow()
{

}
