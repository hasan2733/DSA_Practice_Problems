class Solution {
  public:
    int timer = 0;
    void DFS_visit(int u,vector<vector<int>>&adj,vector<int>&visited,vector<int>&d,vector<int>&f,int &timer){
        visited[u]=1;
        timer++;
        d[u]=timer;
        for(auto v:adj[u])
        {
            if(visited[v]==0)
            {
                DFS_visit(v,adj,visited,d,f,timer);
            }
        }
        timer++;
        f[u]=timer;
    }
    vector<int> DFS(vector<vector<int>>&adj,int V)
    {
        vector<int>visited(V,0);
        vector<int>d(V,0);
        vector<int>f(V,0);
        
        for(int i=0;i<V;i++)
        {
            if(visited[i]==0)
            {
                DFS_visit(i,adj,visited,d,f,timer);
            }
        }
        vector<pair<int,int>>ans1;
        vector<int>ans;
        for(int i=0;i<V;i++)
        {
          ans1.push_back({f[i],i});
        }
        sort(ans1.rbegin(),ans1.rend());
        for(int i=0;i<V;i++)
        {
            ans.push_back(ans1[i].second);
        }
        return ans;
    }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<vector<int>>adj(V);
        for(auto edge:edges)
        {
             int u = edge[0];
             int v = edge[1];
             adj[u].push_back(v);
        }
        return DFS(adj,V);
        
    }
};
