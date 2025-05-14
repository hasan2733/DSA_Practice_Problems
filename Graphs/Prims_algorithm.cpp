class Solution {
  public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        vector<bool>visited(V,false);
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        pq.push({0,0});// wt,src
        int mst=0;
        while(!pq.empty())
        {
            auto vec = pq.top();
            pq.pop();
            if(visited[vec[1]])
             continue;
            mst+=vec[0];
            visited[vec[1]] = true;
            int u = vec[1];
            for(auto neibour:adj[u])
            {
                int v = neibour[0];
                int wt = neibour[1];
                if(!visited[v])
                 pq.push({wt,v});
            }
        }
        return mst;
    }
};
