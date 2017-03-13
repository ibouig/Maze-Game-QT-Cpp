#ifndef SIDEWINDER_H
#define SIDEWINDER_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include "Maze.h"


class SideWinder : public Maze
{
    public:
        SideWinder(int,int);
        ~SideWinder();

    protected:

    private:
};

#endif // SIDEWINDER_H
