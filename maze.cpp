#include "Maze.h"
#include<vector>
#include<iostream>
#include<set>
#include<time.h>
using namespace std;
Maze::Maze(int w , int h)
{
    srand(time(NULL));
    wdth=w;
    hght=h;
    cells=new char*[hght];
    for(int i=0;i<hght;i++)
        cells[i]=new char [wdth];
    for(int i=0;i<hght;i++)
        for(int j=0;j<wdth;j++)
            cells[i][j]=0;
}
void Maze::open(direction a,int I,int J)
{
    switch(a)
    {
        case north:cells[I][J]|= 1<<0 ;
        break;
        case south:cells[I][J]|=1<<2;
        break;
        case east:cells[I][J]|=1<<3;
        break;
        case west:cells[I][J]|=1<<1;
        break;
        case visitp:cells[I][J]|=1<<4;
        break;
        case frontr:cells[I][J]|=1<<5;
        break;
        case visitb:cells[I][J]|=1<<6;
        break;
    }
}

//==============================================================================================================
//==============================================================================================================
void Maze::show()
{
    cout<<endl;
        for(int i=0; i<hght; i++)
        {
            for(int j=0; j<wdth; j++)
            {
                if(!((this->cells[i][j]&2)==2))//16
                    cout<<"|";
                else cout<<" ";
                if(((this->cells[i][j]&5)==5))//192
                    cout<<" ";
                else if ((!((this->cells[i][j]&4)==4))&&(!((this->cells[i][j]&1)==1))) cout<<"=";
                else if(!((this->cells[i][j]&1)==1))//128
                    cout<<"-";
                else if(!((this->cells[i][j]&4)==4))//64
                    cout<<"_";
                if(!((this->cells[i][j]&8)==8))//32
                    cout<<"|";
                else cout<<" ";
            }
            cout<<endl;
        }
}
//-------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------
void Maze::empiler(Pile& p,int& i,int& j){
    Element* nvelem=new Element;
    nvelem->indi=i;
    nvelem->indj=j;
    nvelem->suivant=p;
    p=nvelem;
}

void Maze::sommet(Pile& P,int& i,int& j){
    i=P->indi;
    j=P->indj;
}

void Maze::depiler(Pile& P){
    Element *asupp=P;
    P=P->suivant;
    delete asupp;
}

int Maze::valid(char& Case ,int i,int j,int haut, int larg){
    if (i < 0 || i >=haut || j<0 || j>=larg)// SI LES INDICES DE LA CASE DEPASSE LES BORNES
            return 0;
        if (Case&64)//SI LA CASE EST DEJA MARQUE
            return 0;

        return 1;
}

void Maze::Backtracker(int i,int j,int Ei,int Ej)
{
this->P=NULL;
    while(i!=Ei || j!=Ej)
    {
        if(!(cells[i][j]&64))//SI LA CASE N'EST PAS MARQUé
        {
            empiler(this->P,i,j);
            open(visitb,i,j);
        }//POUR NE PAS RéEMPILER UN SOMMET DEJA MARQUE ET DEJA EMPILER

        if((cells[i][j]&1)&& valid(cells[i-1][j],i-1,j,hght,wdth))//NORTH
            i=i-1;
        else if((cells[i][j]&8)&& valid(cells[i][j+1],i,j+1,hght,wdth))//EST
            j=j+1;
        else if((cells[i][j]&4)&& valid(cells[i+1][j],i+1,j,hght,wdth))//SUD
            i=i+1;
        else if((cells[i][j]&2)&& valid(cells[i][j-1],i,j-1,hght,wdth))//WEST
            j=j-1;
        else
        {
            if(this->P==NULL)
            {
                //BT n'a pas trouver de solution
                return;
            }
            else
            {
                depiler(this->P);
            }
            if(this->P!=NULL)
                sommet(this->P,i,j);
        }
    }
    empiler(this->P,i,j);//EMPILER L'END :DANS CETTE ETAPE ON A i==Ei ET j==Ej

}

Maze::~Maze()
{
    delete []cells;

}

