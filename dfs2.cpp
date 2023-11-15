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
        stack <int> stk;
        stk.push(s);

        while(!stk.empty())
        {
             int cur = stk.top();
             stk.pop();

             if(!visited[cur])
             {
                cout<<cur<<" ";
                visited[cur]=true;
             }

             for(auto x:adj[cur])
             {
                if(!visited[x])
                {
                    stk.push(x);
                }
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