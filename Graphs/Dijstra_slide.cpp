#include <bits/stdc++.h>
using namespace std;
pair<vector<int>,vector<int>> dijstra(int vertices,vector<vector<vector<int>>>&adj,int s)
{
  vector<int>dist(vertices,INT_MAX);
  vector<int>pred(vertices,-1);
  
  priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
  pq.push({0,s});
  dist[s]=0;
  
  while(!pq.empty())
  {
    auto x  = pq.top(); pq.pop();
    int u = x[1];
    for(auto neibour : adj[u])
    {
      int v = neibour[0];
      int wt  = neibour[1];
      if(dist[u]+wt<dist[v])
      {
        dist[v] = dist[u]+wt;
        pred[v] = u;
        pq.push({dist[v],v});
      }
    }
  }
  return {pred,dist};
  
}
int main() 
{
    int vertices,edges,s;
    cin>>vertices>>edges>>s;
    vector<vector<vector<int>>> adj(vertices);
    for(int i=0;i<edges;i++)
    {
      int u,v,wt;
      cin>>u>>v>>wt;
      adj[u].push_back({v,wt});
    }
    
    auto y = dijstra(vertices,adj,s);
    
    auto pre = y.first;
    auto distance = y.second;
    
    for(int i=0;i<vertices;i++)
      cout<<pre[i]<<" ";
    cout<<endl;
    for(int i=0;i<vertices;i++)
      cout<<distance[i]<<" ";
    cout<<endl;
}


/*
u  v  wt 
5 7 2
2 1 2
2 0 3
2 3 7
1 3 3
1 4 6
0 4 1
2 0 3
*/
