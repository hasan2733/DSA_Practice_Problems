class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<vector<int>>> adj(n);
        for(auto edge:flights)
        {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            adj[u].push_back({v,wt});
        }
        vector<vector<int>>dist(n,vector<int>(k+2,INT_MAX));
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        pq.push({0,src,0});
        dist[src][0]=0;
    
        while(!pq.empty())
        {
            auto vec = pq.top();
            pq.pop();
            int u = vec[1];
            int stops = vec[2];
            if(u==dst)
             return dist[u][stops];
             if(stops>k)
              continue;
            for(auto neibour:adj[u])
            {
                int v = neibour[0];
                int wt = neibour[1];
                if(dist[v][stops+1]>dist[u][stops]+wt)
                {
                    dist[v][stops+1] = dist[u][stops]+wt;
                    pq.push({dist[v][stops+1],v,stops+1});
                }
            }
        }
        return -1;
    }
};
