#include <bits/stdc++.h>
using namespace std;

class Graph
{
    public:
    int V;
    vector<vector<pair<int,int>>> adj;
    
    Graph(int vertices)
    {
        V=vertices;
        adj.resize(V);
    }
    
    void addEdge(int u,int v,int weight)
    {
        adj[u].push_back({v,weight});
        adj[v].push_back({u,weight});
    }
    
    void primMST()
    {
        vector<bool> visited(V,false);
        vector<int> key(V,INT_MAX);
        vector<int> parent(V,-1);
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        
        int src=0;
        pq.push({0,src});
        
        while(!pq.empty())
        {
            int u = pq.top().second;
            pq.pop();
            visited[u] = true;
            
            for(const auto & neighbour : adj[u])
            {
                int v = neighbour.first;
                int w = neighbour.second;
                
                if(!visited[v] && key[v]>w)
                {
                    key[v]=w;
                    pq.push({key[v],v});
                    parent[v]=u;
                }
            }
            
            
        }
        
        
        cout<<"Prims Tree:"<<endl;
        
        for(int i=1;i<V;i++)
        {
            cout<<parent[i]<<"-----"<<i<<"   "<<getKey(parent[i],i)<<endl;
        }
    }
    
    int getKey(int u,int v)
    {
        for(const auto & neighbour : adj[u])
        {
            if(neighbour.first==v)
            {
                return neighbour.second;
            }
        }
        
        return INT_MAX;
    }
};

int main()
{
    Graph g(5);

    g.addEdge(0, 1, 2);
    g.addEdge(0, 3, 6);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 3, 8);
    g.addEdge(1, 4, 5);
    g.addEdge(2, 4, 7);
    g.addEdge(3, 4, 9);

    g.primMST();

    return 0;
    
}
