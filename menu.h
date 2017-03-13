#ifndef MENU_H
#define MENU_H
#include <QApplication>
#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QPixmap>
#include <QComboBox>
#include "game.h"
#include <QMediaPlayer>

class menu : public QWidget
{
    Q_OBJECT
public:
    menu(QWidget *parent = 0);
    ~menu();
private:
    QPushButton *play_button;
    QPushButton *about_button;
    QPushButton *howTo_button;
    QPushButton *exit_button;
    QWidget *about_page;
    QWidget *help_page;
    QWidget *score_page;
    QComboBox *levels;
    QMediaPlayer *music;
    QPushButton *music_control;
    static int is_muted;
    QComboBox *avatar;
    QPushButton *score_list;


signals:

public slots:
    void about();
    void help();
    void new_game();
    void menu_sound();
    void score();
};

#endif // MENU_H
