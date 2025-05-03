class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>> &adj) {
        vector<int>ans;
        int total_vertices = adj.size();
        queue<int>q;
        q.push(0);
        vector<bool>visited(total_vertices,false);
        visited[0]=true;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(int neighbor : adj[node])
            {
                if(visited[neighbor]==false)
                {
                    visited[neighbor]=true;
                    q.push(neighbor);
                }
            }
        }
        return ans;
        
    }
};
