#include "SideWinder.h"
#include "Maze.h"
#include <bits/stdc++.h>
#include <ctime>


SideWinder::SideWinder(int a,int b) : Maze(a,b)
{
    int set_start=0;
    int R_cell;
    for(int i=0;i<height;i++)
    {
        set_start=0; //empty the set for each row
        for(int j=0;j<width;j++)
        {
            //each time if the random number=0 we remove the north
            //else we remove the east
            if(i>0 && (j+1==width || (rand()%2)==0))
            {
                R_cell = set_start + rand()%(j - set_start + 1);
                set_bit(up,i,R_cell);//removing the north wall of cell means removing the south of the upper cell
                set_bit(down,i-1,R_cell);
                set_start = j+1; //start the set from the next cell
            }
            else if(j+1<width)
            {
                set_bit(right,i,j);//removing the east wall of cell means removing the west of the next cell
                set_bit(left,i,j+1);
            }
        }
    }
    solve_maze(0,0);
}

SideWinder::~SideWinder()
{
    //dtor
}


