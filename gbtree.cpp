#include "gbtree.h"
#include"maze.h"
#include<set>
using namespace std;

Gbtree::Gbtree(int n,int m):Maze(n,m)
        {
            int y,p1,p2,indice,x,nbr_vois,i1,j1,ip1,ip2,coord;
            int compt=1,compt2=1,compt3=1,compt4=1/*,comptai=1*/;//compter le nombre de cellules deja traiter
            set<int> champ;
            set<int>::iterator it;//parcour dant le champ
            set<int> voisin;//pour collecter tout les voisins troouvee
            set<int>::iterator itt;
            x=rand()%(hght*wdth); //choisir INDICE D'une cellule dans le graphe aleatoirement
            open(visitp,x/wdth,x%wdth);
            champ.insert(x);
    while(champ.size()!=0)
    {
        p1=5,p2=5;//les portes a open

        y=rand()%champ.size();//choisir l'indice d'un sommet de champ alleatoirement
        it = champ.begin();
        std::advance(it,y);//ppointer it vers l'indice y de champ
        indice= *it;//car on ajoute l'indice de la cellule dans le champ

        compt=1,compt2=1,compt3=1,compt4=1;
        i1=indice/wdth;
        j1=indice%wdth;
        nbr_vois=0;
        voisin.clear();//initier la taille des voisins de cellule
        if(i1-1>=0)
            compt=cells[i1-1][j1]&16;
        if(j1-1>=0)
            compt2= cells[i1][j1-1]&16;
        if(i1+1<hght)
            compt3=cells[i1+1][j1]&16;
        if(j1+1<wdth)
            compt4=cells[i1][j1+1]&16;

        if( compt==0)//nord
        {
            nbr_vois+=1;
            voisin.insert(0);
        }
        if(compt3==0)//sud
        {
            nbr_vois+=1;
            voisin.insert(2);
        }

        if(compt2==0 )//west
        {
            nbr_vois+=1;
            voisin.insert(1);
        }
        if(compt4==0)//est
        {
            nbr_vois+=1;
            voisin.insert(3);
        }

        if(nbr_vois==0)//tout les voisins de la cellule sont deja visitee
        {
            champ.erase(indice);
        }
        else
        {
            ip1=rand()% voisin.size(); //indice de la porte dans le vecteur
            itt = voisin.begin();
            std::advance(itt,ip1);
            p1= *itt;
            voisin.erase(p1);

            if(voisin.size()!=0)
            {
                ip2=rand()% voisin.size();
                itt = voisin.begin();
                std::advance(itt,ip2);
                p2= *itt;
            }
            if(((p1==0)||(p2==0))&&(i1 !=0))
            {
                open(north,i1,j1);
                open(south,i1-1,j1);
                open(visitp,i1-1,j1);//MARQUER LE VOISIN COMME VISITE
                coord=(i1-1)*wdth + j1;
                champ.insert(coord);//INSERER LE VOISIN
            }
            if(((p1==1)||(p2==1))&&(j1 !=0))//west
            {
                open(west,i1,j1);
                open(east,i1,j1-1);
                open(visitp,i1,j1-1);
                coord=(i1)*wdth + j1-1;
                champ.insert(coord);
            }
            if(((p1==2)||(p2==2))&&(i1 !=hght-1))//south
            {
                open(south,i1,j1);
                open(north,i1+1,j1);
                open(visitp,i1+1,j1);
                coord=(i1+1)*wdth + j1;
                champ.insert(coord);
            }
            if(((p1==3)||(p2==3))&&(j1 !=wdth-1))//est
            {
                open(east,i1,j1);
                open(west,i1,j1+1);
                open(visitp,i1,j1+1);
                coord=(i1)*wdth + j1+1;
                champ.insert(coord);
            }
            champ.erase(indice);
        }
    }

for(int i=0;i<hght;i++)
    for(int j=0;j<wdth;j++)
       {
           open(frontr,i,j);
           open(visitp,i,j);
       }
          }




Gbtree::~Gbtree()
{

}

