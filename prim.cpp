#include "Prim.h"
using namespace std;

void Prim::add_frontier(int i,int j,vector<pair<int,int>>& frontier)
{
    if(i>=0 && j>=0 && i<width && j<height && !(cell[i][j]&front)) //not yet FRONTIER
        {
            set_bit(FRONTR,i,j);
            frontier.push_back(make_pair(i,j));
        }
}

void Prim::marquer_cell(int i,int j,vector<pair<int,int>>& frontier)
{
    set_bit(IN,i,j);
    add_frontier(i-1,j,frontier);
    add_frontier(i+1,j,frontier);
    add_frontier(i,j-1,frontier);
    add_frontier(i,j+1,frontier);

}

void Prim::neighbors(int i,int j,vector<pair<int,int>>& n)
{
        if (i>0 && (this->cell[i-1][j]&in)) //in=16
            n.push_back(make_pair(i-1,j));
         if (i+1<width && (this->cell[i+1][j]&in))
            n.push_back(make_pair(i+1,j));
        if (j>0 && (this->cell[i][j-1]&in))
            n.push_back(make_pair(i,j-1));
        if (j+1<height && (this->cell[i][j+1]&in))
            n.push_back(make_pair(i,j+1));
}

Prim::direction Prim::to_direction(int fx,int fy,int tx,int ty)
{
    if (fx < tx)
        return down;
    if (fx > tx)
        return up;
    if (fy < ty)
        return right;
    if (fy > ty)
        return left;
    return IN; // to avoid the warning it will never reach this line
}

Prim::Prim(int h,int w):Maze(h,w)
{
    vector<pair<int,int>> frontier;
    vector<pair<int,int>> neighbor;
    int i1= rand()%height;
    int j1= rand()%width;
    int a,b,x,y,neighbor_x,neighbor_y;
    //start by marking a random cell
    marquer_cell(i1,j1,frontier);
    set_bit(FRONTR,i1,j1); //to not add it again in Add_frontier
    //iterate until the frontier set is empty:
    while(!frontier.empty())
    {
        //Within the loop, we choose a frontier cell at random
        a = rand()%frontier.size();
        x = frontier[a].first;
        y = frontier[a].second;
        frontier.erase(frontier.begin()+a);
        neighbors(x,y,neighbor);
        //Then we choose a random “in” neighbor of that frontier cell:
        b = rand()%neighbor.size();
        neighbor_x = neighbor[b].first;
        neighbor_y = neighbor[b].second;
        //we record a passage from the neighbor cell to the frontier cell:
        set_bit(to_direction(x,y,neighbor_x,neighbor_y),x,y);
        set_bit(to_direction(neighbor_x,neighbor_y,x,y),neighbor_x,neighbor_y);
        //we mark the frontier cell as being “in” the maze (and add any of its outside neighbors to the frontier):
        marquer_cell(x,y,frontier);
        neighbor.clear();
    }
    solve_maze(0,0);
}

Prim::~Prim()
{
    //dtor
}


