#ifndef JEU_H
#define JEU_H

#include <QObject>
#include <QWidget>
#include<QGridLayout>
#include<QLabel>
#include<QMainWindow>
#include "board.h"
#include<QPushButton>
#include "mylabel.h"
#include<QMessageBox>
#include<QTime>
#include<QTimer>

enum choix {easy , medium , hard } ;

class jeu:public QMainWindow
{
    Q_OBJECT

public slots:
    void resolve();
    void rejoue();
    void fin();
    void update_time();
signals :
    void fin_s();
public:
    int choice ;
    bool cas;
    int Ci,Cj;
    Board * b;
    QPushButton * solution;
    QPushButton * rejouer;
    QPushButton *quitter;
    QTimer* timer;
    QTime *time_elapsed;
    QLabel* time_label;
    QLabel* A_Plan;
public:
    void keyReleaseEvent(QKeyEvent* event);
    jeu(int choix);
    ~jeu();
};

#endif // JEU_H
