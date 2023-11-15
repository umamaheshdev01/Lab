#include <bits/stdc++.h>
using namespace std;

class Graph
{
    public :
    int V;
    vector<vector<pair<int,int>>> adj;

    Graph(int x)
    {
        V = x;
        adj.resize(x);
    }

    void addEdge(int u,int v,int w)
    {
        adj[u].push_back({v,w});
        adj[v].push_back({u,w}); //undirected;
    }

    void bellman(int src)
    {
         vector<int> dis(V,INT_MAX);
         dis[src]=0;

         for(int i=0;i<V-1;i++)
         {
            for(int u=0;u<V;u++)
            {
                for(auto x:adj[u])
                {
                    int v = x.first;
                    int w = x.second;

                    if(dis[u]!=INT_MAX && dis[u]+w<dis[v])
                    {
                        dis[v]=dis[u]+w;
                    }

                }
            }
         }

         //negative cycle check


         for(int u=0;u<V;u++)
            {
                for(auto x:adj[u])
                {
                    int v = x.first;
                    int w = x.second;

                    if(dis[u]!=INT_MAX && dis[u]+w<dis[v])
                    {
                        cout<<"Negative cycle found"<<endl;
                        return;
                    }

                }
            }

        cout<<"Shortest distances:"<<endl;
        for(int i=0;i<V;i++)
        {
            cout<<i<<" : "<<dis[i]<<endl;
        }


    }
};

int main()
{
     Graph g(4);
     g.addEdge(0,1,10);
     g.addEdge(1,2,3);
     g.addEdge(2,3,1);
     g.addEdge(3,0,6);

     g.bellman(0);

}