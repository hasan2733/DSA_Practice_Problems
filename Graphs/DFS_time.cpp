#include<bits/stdc++.h>
using namespace std;

int WHITE = 0;
int GRAY = 1;
int BLACK =2;

void DFS_visit(int u,vector<vector<int>>&adj,vector<int>&color,vector<int>&d,vector<int>&f,int &timer)
{
  color[u]=GRAY;
  timer++;
  d[u]=timer;
  
  int n = adj.size();
  
  for(int v=0;v<n;v++)
  {
    if(adj[u][v]==1 && color[v]==WHITE)
    {
      DFS_visit(v,adj,color,d,f,timer);
    }
  }
  color[u]=BLACK;
  timer++;
  f[u]=timer;
}

void DFS(vector<vector<int>>&adj)
{
  int n = adj.size();
  vector<int>color(n);
  vector<int>d(n);
  vector<int>f(n);
  int timer = 0;
  
  for(int i=0;i<n;i++)
  {
    color[i]=WHITE;
    d[i]=0;
    f[i]=0;
  }
  
  for(int i=0;i<n;i++)
  {
    if(color[i]==WHITE)
    {
      DFS_visit(i,adj,color,d,f,timer);
    }
  }
  
  // result
  for(int i=0;i<n;i++)
  {
    cout<< "Vertex "<<i<<" discovery time "<<d[i]<<" finishing time "<<f[i]<<endl;
  }
}
void addedges(int u ,int v,vector<vector<int>>&adj)
{
  adj[u][v]=1;
  adj[v][u]=1;
}
int main()
{
  int vectices,edges;
  cin>>vectices>>edges;
  vector<vector<int>>adj(vectices,vector<int>(vectices,0));
  for(int i=0;i<edges;i++)
  {
    int u,v;
    cin>>u>>v;
    addedges(u,v,adj);
  }
  DFS(adj);
  
}


// undirected graph
// 5
// 6
// 0 1
// 0 2
// 1 2
// 1 3
// 2 4
// 3 4
