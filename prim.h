#ifndef PRIM_H
#define PRIM_H
#include<vector>
#include"maze.h"
class Prim :public Maze{
public:
    Prim(int n,int m);
    void Ajouter_F(int ,int ,std::vector<int> &);
    void marquer(int ,int ,std::vector<int> &);
    direction direction1 (int ,int ,int ,int );
    ~Prim();
};
#endif // PRIM_H
