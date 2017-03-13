#include "growing_tree.h"
#include <bits/stdc++.h>
using namespace std;

growing_tree::growing_tree(int a,int b) : Maze(a,b)
{
    //Shuffle
      vector<int> direction_index;
      for (int i=0; i<4; ++i) direction_index.push_back(i); //0 1 2 3
      //We want random number from 0 to 3 to be chosen only once in a loop!
      random_shuffle ( direction_index.begin(), direction_index.end() );


    //Choose_random_start_cell
    stack<pair<int,int>> pile; // Will be used to store current cell and delete it once we're done using it!
    pair<int,int> Neig; //Coord of Neighbor
    pair<int,int> Coord;
    Coord = make_pair(rand()%height,rand()%width); //growing tree like backtrack starts with random cell
    pile.push(Coord);    //Cells stored in stack in seconder to load the most recent one always!
    int neighbor_found;



    //Principal_Loop
      while (!pile.empty())
      {
        pair<int,int> index;
        index=make_pair(pile.top().first,pile.top().second);
        neighbor_found=0;
        int DX[4]={-1,1,0,0}, //Used to calculate neighbor cosecondinates X
            DY[4]={0,0,1,-1}, //and Y
            Opposite[4]={1,0,3,2};//Delete a given cell's wall means deleting the chosen neighbor's
                                   // wall in the opposite direction
        random_shuffle ( direction_index.begin(), direction_index.end() );
        // We shuffle before "while" and within loop itself!

      //Find_Way_loop
        for (vector<int>::iterator it=direction_index.begin(); it!=direction_index.end(); ++it)
        {
          int dir=*it; //We retrieve shuffled number in dir
          Neig.first=index.first + DX[dir]; //Calculate Neighbor cosecondinates
          Neig.second=index.second + DY[dir];
          if (Neig.first >= 0 && Neig.second >= 0 && Neig.first < height && Neig.second < width && cell[Neig.first][Neig.second] == 0) // ==0 means not visited
            //See whether the cell is already visited or out of bound
            {
                try{
              set_bit(int_to_Dir(dir),index.first,index.second);
                }
                catch(int n)
                {
                    if (n <0 || n>3)
                  cerr << "Iterator out_of_bound";
                }
              set_bit(int_to_Dir(Opposite[dir]),Neig.first,Neig.second);
              pile.push(Neig);
              neighbor_found=1;
              break;
            }
        }

          if(!neighbor_found)
            pile.pop();
        }
      solve_maze(0,0);

}


Maze::direction growing_tree::int_to_Dir(int n)
{
    switch(n)
    {
        case 0: return up;break;
        case 1: return down;break;
        case 2: return right;break;
        case 3: return left;break;
        default: throw(n); break;
    }
}
growing_tree::~growing_tree()
{
    //dtor
}


