class Solution {
   vector<int>parent,size;
   public :
   void make(int a)
   {
       parent[a] = a;
       size[a]=1;
   }
   int find(int a)
   {
       if(parent[a]==a)
        return a;
       return parent[a] = find(parent[a]);
   }
   void unite(int a,int b)
   {
       a = find(a);
       b = find(b);
       if(a!=b)
       {
       if(size[a]>size[b])
        swap(a,b);
       parent[a]=b;
       size[b]+=size[a];
       }
   }
   static bool comp(vector<int>&a,vector<int>&b)
   {
       return a[2]<b[2];
   }
  public:
    int kruskalsMST(int V, vector<vector<int>> &edges) {
        parent.resize(V);
        size.resize(V);
        for(int i=0;i<V;i++)
        {
            make(i);
        }
        sort(edges.begin(),edges.end(),comp);
        int mst = 0;
        for(auto edge:edges)
        {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            if(find(u)!=find(v))
            {
                unite(u,v);
                mst+=wt;
            }
        }
        return mst;
    }
};
