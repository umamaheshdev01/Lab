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

    void dijikstra(int src)
    {
        vector<int> dis(V,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

        pq.push({0,src});
        dis[src]=0;

        while(!pq.empty())
        {
            int u = pq.top().second;
            pq.pop();

            for(auto neighbour:adj[u])
            {
                int v = neighbour.first;
                int w = neighbour.second;

                if(dis[u]+w<dis[v])
                {
                    dis[v]=dis[u]+w;
                    pq.push({dis[v],v});
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

     g.dijikstra(0);

}