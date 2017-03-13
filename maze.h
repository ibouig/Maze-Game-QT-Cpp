#ifndef MAZE_H
#define MAZE_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <bits/stdc++.h>
using namespace std;


class Maze
{
    public:

        int height;
        int width;
        char** cell;
        enum direction{up,down,right,left,IN,FRONTR,BACKTRACK};
        int in=0x10; //16
        int front=0x20;//32
        int backt= 0x40; //64

        stack<pair<int,int>> chemin;
        Maze(int,int);
        virtual ~Maze();
        void set_bit(direction,int i,int j);
        void show();
        void solve_maze(int i,int j);
        bool is_safe(int i,int j);
    private:

};

#endif // MAZE_H
