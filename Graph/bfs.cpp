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

    void bfs(int s)
    {
        vector<bool> visited(V,false);
        queue<int> q;

        q.push(s);
        visited[s]=true;

        while(!q.empty())
        {
            int cur = q.front();
            q.pop();
            cout<<cur<<" ";

            for(auto x : adj[cur])
            {
                if(!visited[x])
                {
                q.push(x);
                visited[x]=true;
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

     g.bfs(0);
}