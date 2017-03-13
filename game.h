#ifndef GAME_H
#define GAME_H

#include <QApplication>
#include <QObject>
#include <QWidget>
#include "prim.h"
#include "growing_tree.h"
#include "sidewinder.h"
#include "bits/stdc++.h"
#include <QPushButton>
#include <QLabel>
#include "menu.h"
#include <QLayout>
#include <QGridLayout>
#include <QMediaPlayer>
#include <QKeyEvent>
#include <QTime>
#include <QTimer>
using namespace std;

class game : public QWidget
{
    Q_OBJECT
public:
    int x_position=0,y_position=0,time,score=100,initial,solve_begin;
    game(int lvl=0, int avtr=0);
    ~game();
    void set_game(int lvl,int avtr);
    void generate_maze();
    void win();
    void lose();
    void write_score() ;

private:

    QPushButton *exit_game;
    QPushButton *solve_game;
    QPushButton *hint_game;
    QPushButton *tryAgain;
    QLabel *timing,*time_bg,*time_board;
    QLabel *score_bg,*score_board,*scoring;
    QLabel *maze_grid;
    Maze * maze;
    int level=0,dim=0;
    QLabel **square;
    QWidget *game_space;
    QGridLayout *game_layout;
    QPixmap *avatar,*flag,*empty,*late;
    int **solution;
    int hint_number=0;
    int gameMute=0,effectMute=0,is_solved=0;
    QMediaPlayer *GameSound_control,*MoveSound,*ErrorSound,*winSound,*loseSound,*DangerSound;
    QPushButton *GameSound,*SoundEffect;
    QTimer *timer;

signals:

public slots:
    void exit_app();
    void hint_box();
    void solve();
    void GameSound_button();
    void SoundEffect_button();
    void again();
    void My_timer();
    void keyPressEvent (QKeyEvent * event);

};

#endif // GAME_H
