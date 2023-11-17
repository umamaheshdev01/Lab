#include <bits/stdc++.h>
using namespace std;

class HamiltonianGraph{
    
    public:
    
    int V;
    vector<vector<int>> adj;
    
    HamiltonianGraph(int x)
    {
        V=x;
        adj.resize(x,vector<int>(x,0));
    }
    
    void addEdge(int u ,int v)
    {
        adj[u][v]=1;
        adj[v][u]=1;
    }
    
    bool isHamiltonian()
    {
        vector<int> path;
        vector<bool> visited(V,false);
        
        path.push_back(0);
        visited[0]=true;
        
        return hamilUtil(path,visited);
    }
    
    bool hamilUtil(vector<int> & path,vector<bool>&visited )
    {
        if(path.size()==V)
        {
            if(adj[path.back()][path.front()]==1)
            {
                cout<<"Hamiltonaian Cycel :"<<endl;
                for(auto x:path)
                {
                    cout<<x<<" ";
                }
                
                cout<<path.front()<<endl;
                return true;
            
            }
            return false;
            
        }
        
        
        for(int v=0;v<V;v++)
        {
            if(adj[path.back()][v]==1 & !visited[v])
            {
                path.push_back(v);
                visited[v]=true;
                
                if(hamilUtil(path,visited))
                {
                    return true;
                }
                
                path.pop_back();
                visited[v]=false;
            }
        }
        
        return false;
    }
    
};

int main()
{
    HamiltonianGraph g(5);

    g.addEdge(0, 1);
    g.addEdge(0, 3);
    g.addEdge(1, 2);
    g.addEdge(1, 4);
    g.addEdge(2, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    if (!g.isHamiltonian()) {
        cout << "No Hamiltonian Cycle found." << endl;
    }

    return 0;
}
