class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        vector<vector<vector<int>>> adj(V);
        for(auto edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        vector<int>dist(V,INT_MAX);
        pq.push({0,src});
        dist[src]=0;
        while(!pq.empty())
        {
            int u = pq.top()[1];
            pq.pop();
            for(auto neibour:adj[u])
            {
                int v = neibour[0];
                int wt = neibour[1];
                if(dist[v]>dist[u]+wt)
                {
                    dist[v]=dist[u]+wt;
                    pq.push({dist[v],v});
                }
            }
        }
        return dist;
        
    }
};
