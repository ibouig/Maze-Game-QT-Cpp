#ifndef FENETRE_H
#define FENETRE_H

#include "jeu.h"
#include<QApplication>
#include<QRadioButton>
#include<QSlider>
#include<QFileInfo>
#include<QComboBox>
#include<QVBoxLayout>

class fenetre : public QWidget// ,public jeu
{
    Q_OBJECT //CEST UNE MACRO POUR PREPARER POUR LES SLOTS
public:
    fenetre(int a,int b)  ;//constructeur
public slots:
    void backgr();
    void interm();
    void instruc();
    void aboutt();

private:

    QSlider * slid;//redimentionner la fenetre
    QPushButton *play;
    QPushButton *instruction;
    QPushButton *exit;
    QPushButton *about;
    QComboBox *lev;//liste deroulant pour choix de niveau
    QLabel *choose;
    QWidget * inst;//fenetre d'instructions
    QWidget * ab;//fenetre de about us

};

#endif // FENETRE_H
