#ifndef PRIM_H
#define PRIM_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include "Maze.h"
#include <bits/stdc++.h>

using namespace std;

class Prim : public Maze
{
    public:

        Prim(int,int);
        ~Prim();
        void add_frontier(int i,int j,vector<pair<int,int>> & frontier);
        void marquer_cell(int i,int j,vector<pair<int,int>>& frontier);
        void neighbors(int i,int j,vector<pair<int,int>>& n);
        direction to_direction(int fx,int fy,int tx,int ty);

    protected:

    private:
};

#endif // PRIM_H
