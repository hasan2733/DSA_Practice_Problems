class Solution {
public:

// here use DFS and topological sort
void DFS_visit(int u,vector<vector<int>>&adj,vector<int>&visited,vector<int>&d,vector<int>&f,int &timer,bool &cycle)
    {
        visited[u] = 1;
        timer++;
        d[u]=timer;
        for(auto v:adj[u])
        {
            if(visited[v]==0)
             DFS_visit(v,adj,visited,d,f,timer,cycle);
            else if(visited[v]==1)
              cycle = true;
        }
        visited[u]=2;
        timer++;
        f[u]=timer;
    }
    
    pair<vector<int>, bool> DFS(int V, vector<vector<int>>&adj)
    {
       vector<int>visited(V,0);
       vector<int>d(V,0);
       vector<int>f(V,0);
       int timer = 0;
       bool cycle = false;

       for(int i=0;i<V;i++)
       {
        if(visited[i]==0)
         DFS_visit(i,adj,visited,d,f,timer,cycle);
       }
       
       vector<pair<int,int>> ans1;
       vector<int> ans;
       for(int i=0;i<V;i++)
       {
         ans1.push_back({f[i],i});
       }
       sort(ans1.rbegin(),ans1.rend());

       for(int i=0;i<V;i++)
       {
         ans.push_back(ans1[i].second);
       }

       return {ans,cycle};
    }

    pair<vector<int>, bool> toposort(int V,vector<vector<int>>&edges)
    {
        vector<vector<int>>adj(V);
        for(auto edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
        }

        return DFS(V,adj);

    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> edges;
        for(auto pre: prerequisites)
        {
            edges.push_back({pre[1],pre[0]});
        }
        auto topo = toposort(numCourses,edges);
        return !topo.second;
    }
};
