#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dx[] = {-1,1,0,0}; //left right
int dy[] = {0,0,-1,1}; //up down

bool valid(int x,int y,vector<string>&Maze, vector<vector<bool>>&visited)
{
   int rows = Maze.size();
   int coloumns = Maze[0].size();
   
   return x>=0 && x<rows && y>=0 && y<coloumns && Maze[x][y]!= '0' && !visited[x][y];
}

int BFS(pair<int,int> start, pair<int,int> target, vector<string>&Maze)
{
   int rows = Maze.size();
   int coloumns = Maze[0].size();
   
   vector<vector<bool>>visited(rows,vector<bool>(coloumns,false));
   queue<pair<pair<int,int>,int>> q;
   
   q.push({start,0});
   visited[start.first][start.second]=true;
   
   while(!q.empty())
   {
     auto [pos,steps] = q.front();
     q.pop();
     int x = pos.first ;
     int y = pos.second;
     if(target==pos)
      return steps;
    
    for(int i=0;i<4;i++)
    {
      int ax = x + dx[i]; 
      int ay = y + dy[i];
      if(valid(ax,ay,Maze,visited))
      {
        visited[ax][ay] = true;
        q.push({{ax,ay},steps+1});
      }
    }
   }
   return -1;
}
int main() 
{
    vector<string> Maze = 
    {
        "S0.T",
        "..0.",
        "....",
        "0...",
        "..0."
    };
    
    pair<int,int> start,target;
    
    for(int i = 0;i<Maze.size();i++)
    {
      for(int j = 0;j<Maze[0].size();j++)
      {
        if(Maze[i][j]=='S')
         start = {i,j};
        if(Maze[i][j]=='T')
         target = {i,j};
      }
    }
    
    int ans = BFS(start,target,Maze);
    
    cout<<"Minimum steps S to T is : "<<ans<< " steps"<<endl;
    
}
