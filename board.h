#ifndef BOARD_H
#define BOARD_H

#include <QMainWindow>
#include<QWidget>
#include<QGridLayout>
#include<QLabel>
#include<QPixmap>
#include"jeu.h"
#include"prim.h"
#include"sidew.h"
#include"gbtree.h"
#include"mylabel.h"

class Board:public QWidget
{
    //Q_OBJECT
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;

    QPixmap pixmap;
    Maze * m;

public:
    void show();
    int t;

    mylabel **labeltab;
    QLabel* A_Plan;
    Board(QMainWindow *parent,int choix);//constructeur
    ~Board();
    void newGame();
    void drawSolution(int Ci,int Cj);
protected:
};

#endif // BOARD_H
