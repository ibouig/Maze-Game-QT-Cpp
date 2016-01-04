#include "sidew.h"
#include"maze.h"

SideW::SideW(int n,int m):Maze(n,m){
    int R=0,y_cell;

      for(int i=0;i<hght;i++)
      {
          R=0;
          for(int j=0;j<wdth;j++)
          {
              if((i>0)&&((j+1==wdth)||(rand()%2==0)))
                {
                    y_cell=R+rand()%(j-R+1);
                    open(north,i,y_cell);
                    open(south,i-1,y_cell);
                    R=j+1;
                }
              else if((j+1<wdth))
              {
                  open(east,i,j);
                  open(west,i,j+1);
              }
          }
      }
      for(int i=0;i<hght;i++)
          for(int j=0;j<wdth;j++)
             {
                 open(frontr,i,j);
                 open(visitp,i,j);
             }

}


SideW::~SideW()
{

}

