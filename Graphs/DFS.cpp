class Solution {
  public:
    vector<int> dfs(vector<vector<int>>& adj) {
        stack<int>stk;
        vector<int>res;
        vector<bool>visited(adj.size(),false);
        stk.push(0);
        while(!stk.empty())
        {
            int node = stk.top();
            stk.pop();
            if(visited[node])
              continue;
            visited[node]=true;
            res.push_back(node);
            for(int i=adj[node].size()-1;i>=0;i--)
            {
                if(visited[adj[node][i]]==false)
                {
                   stk.push(adj[node][i]);
                }
            }
        }
        return res;
        
    }
};
