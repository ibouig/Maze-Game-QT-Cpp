#include "prim.h"
#include"maze.h"
#include<vector>
using namespace std;

void Prim::Ajouter_F(int i,int j,vector<int> &frontier )
{
    if(i>=0 && j>=0 && i<wdth && j<hght && cells[i][j]==0)
    {
        open(frontr,i,j);
        frontier.push_back(j+i*wdth);    //Pour ajouter la coordonnée des frontieres
    }
}
void Prim::marquer(int i,int j,vector<int> &frontier)
{
    open(visitp,i,j);
    Ajouter_F(i-1,j,frontier);
    Ajouter_F(i+1,j,frontier);
    Ajouter_F(i,j-1,frontier);
    Ajouter_F(i,j+1,frontier);
}

Prim::direction Prim::direction1 (int x,int y,int nx,int ny)   // savoir quelle direction open pour appeler la fct open
{
    if (x<nx)
        return south ;
    if (x>nx)
        return north ;
    if (y<ny)
        return east ;
    if (y>ny)
        return west ;
}

Prim::Prim(int p_h,int p_w):Maze(p_h,p_w){
    int d,f;
    int x,y;
    int nx,ny;
    int ver=0x10;
    vector<int>  frontier;
    vector<int>  n;
    int s1=rand()%wdth;
    int s2=rand()%hght;
    marquer(s1,s2,frontier);
    open(frontr,s1,s2);
    while (frontier.size()!=0)
    {
        d=(rand()%frontier.size());
        int i1=frontier[d];
        frontier.erase(frontier.begin()+d);
        x=i1/wdth;
        y=i1%wdth;
        if (x>0 && (this->cells[x-1][y] & ver))
            n.push_back((x-1)*wdth+y);
         if (x+1<wdth && (this->cells[x+1][y] & ver))
            n.push_back((x+1)*wdth+y);
        if (y>0 && (this->cells[x][y-1] & ver))
            n.push_back(x*wdth+(y-1));
        if (y+1<hght && (this->cells[x][y+1] & ver))
            n.push_back(x*wdth+(y+1));
        f=(rand()%n.size());
        int i2=n[f];
        nx=i2/wdth;
        ny=i2%wdth;
        open(direction1(x,y,nx,ny),x,y);
        open(direction1(nx,ny,x,y),nx,ny);
        marquer(x,y,frontier);
        n.clear();
}
}

Prim::~Prim()
{

}

