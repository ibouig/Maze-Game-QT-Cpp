#include <maze.h>
#include <ctime>
#include <bits/stdc++.h>


using namespace std;

Maze::Maze(int h,int w)
{
    srand(time(0)); //to have a perfect random activity
    height = h;
    width = w;
    cell = new char*[h];
    for(int i=0;i<h;i++)
        cell[i] = new char[w];

    for(int i=0;i<h;i++)
        for(int j=0;j<w;j++)
            cell[i][j]= 0;
}

void Maze::set_bit(direction d, int i,int j)
{

    switch(d)
    {
        case up: cell[i][j] |= 1<<0;break; //pour 1
        case down: cell[i][j] |= 1<<1;break; //pour 2
        case right: cell[i][j] |= 1<<2;break; //pour 4
        case left: cell[i][j] |= 1<<3;break; //pour 8
        case IN: cell[i][j] |= 1<<4;break; //16
        case FRONTR: cell[i][j] |= 1<<5;break; //32
        case BACKTRACK: cell[i][j] |= 1<<6;break; //64
    }


}

void Maze::show()
{

    cout<<endl;
    for(int i=0; i<height; i++)
        {
            for(int j=0; j<width; j++)
            {
                if(!(this->cell[i][j]&8)) //8=L
                    cout<<"|";
                else cout<<" ";

                if ((!(this->cell[i][j]&2))&&(!(this->cell[i][j]&1))) cout<<"="; //2=D 1=U
                else if(!(this->cell[i][j]&1))
                    cout<<"-";
                else if(!(this->cell[i][j]&2))
                    cout<<"_";
                else
                    cout << " ";

                if(!(this->cell[i][j]&4)) //4=R
                    cout<<"|";
                else cout<<" ";
            }
            cout<<endl;
        }
}

bool Maze::is_safe(int i,int j)
{

    if(i<0 || j<0 || i>=height || j>=width)
    {
        return false;
    }
    //IF THE CELL IS ALREADY VISTED RETURN FALSE
    if(cell[i][j]&backt)
        return false;
    return true;
}

//Backtracking
void Maze::solve_maze(int i,int j)
{
    int h=height-1;
    int w=width-1;
    while(i!=h || j!=w)
    {
        //PUSH A NONE VISITED CELL
        if(!(cell[i][j]&backt))
        {
            chemin.push(make_pair(i,j));
            set_bit(BACKTRACK,i,j);
            //cout << i << "," << j <<endl;
        }
        if((cell[i][j]&2) && (is_safe(i+1,j))) //CHECK DOWN
            i++;
        else if((cell[i][j]&1) && (is_safe(i-1,j))) //CHECK UP
            i--;
        else if((cell[i][j]&4) && (is_safe(i,j+1))) //CHECK RIGHT
            j++;
        else if((cell[i][j]&8) && (is_safe(i,j-1))) //CHECK LEFT
            j--;
        else
        {
            if(chemin.empty())
            {
                return; //no solution
            }
            else
            {
                //backtracking
                chemin.pop();
                i=chemin.top().first;
                j=chemin.top().second;
                //cout << i << "," << j <<endl;
            }

        }
    }
    chemin.push(make_pair(i,j)); //ADD THE DESTINATION(n-1,n-1) TO THE STACK
    //cout << i << "," << j <<endl;

    //RESET the IN,FRONTR,BACKTRACK bits to 0
    for(int i=0; i<height; i++)
        for(int j=0; j<width; j++)
            cell[i][j] &= 15;
}

Maze::~Maze()
{
    delete [] cell;
}

