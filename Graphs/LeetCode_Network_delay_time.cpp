class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<vector<int>>>adj(n);
        for(auto edge:times)
        {
            int u = edge[0]-1;
            int v = edge[1]-1;
            int wt = edge[2];
            adj[u].push_back({v,wt});
        }

        vector<int>dist(n,INT_MAX);
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        pq.push({0,(k-1)});
        dist[k-1]=0;
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
        int maxi = dist[0];
        for(int i=0;i<n;i++)
        {
            if(dist[i]==INT_MAX)
              return -1;
            if(maxi<dist[i])
             maxi = dist[i];
        }
        return maxi;
    }
};
