#ifndef MAZE_H
#define MAZE_H
#include <QWidget>
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<vector>
#include<time.h>
struct Element{
    int indi;
    int indj;
    Element* suivant;
    };
typedef struct Element* Pile;

class Maze
{
protected:
    int wdth,hght;
    enum direction {visitb,frontr,visitp,west,east,south,north};
    char** cells;


    public:
    Pile P;
        char **gettab()
        {return cells ;}
        Maze(int,int);
        virtual ~Maze();
        void open(direction ,int ,int );
        void show();
        Maze(const Maze& other);
        Maze& operator=(const Maze& other);
        void Backtracker(int,int ,int,int );
        void empiler(Pile& ,int& ,int&);
        void sommet(Pile& ,int&,int& );
        void depiler(Pile&);
        void affich();
        int valid(char& ,int ,int ,int, int);

    private:
};
#endif // MAZE_H
