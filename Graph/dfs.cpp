#include <bits/stdc++.h>
using namespace std;

class Graph
{
    public:
    int V;
    vector<list<int>> adj;

    Graph(int x)
    {
       V=x;
       adj.resize(x);
    }

    void addEdge(int u,int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u); // undirected graph
    }

    void dfs(int s)
    {
        vector<bool> visited(V,false);
        dfs_util(s,visited);
    }

    void dfs_util(int s,vector<bool> &visited)
    {
         visited[s]=true;
         cout<<s<<" ";

         for(auto x:adj[s])
         {
            if(!visited[x])
            {
                dfs_util(x,visited);
            }
         }
    }

   

};

int main()
{
     Graph g(5);
     g.addEdge(0,1);
     g.addEdge(1,2);
     g.addEdge(2,3);
     g.addEdge(3,0);

     g.dfs(0);
}