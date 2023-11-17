#include <bits/stdc++.h>
using namespace std;

class Graph{
    
    public:
    int V;
    vector<vector<int>> adjMatrix;
    
    Graph(int x)
    {
        V=x;
        adjMatrix.resize(x,vector<int>(V,INT_MAX));
        
        for(int i =0;i<V;i++)
        {
          adjMatrix[i][i]=0;
        }
    }
    
    void addEdge(int u,int v,int w)
    {
        adjMatrix[u][v]=w;
    }
    
    void floyd()
    {
        for(int k=0;k<V;k++)
        {
            for(int i=0;i<V;i++)
            {
                for(int j=0;j<V;j++)
                {
                    if(adjMatrix[i][k]!=INT_MAX && adjMatrix[k][j]!=INT_MAX && adjMatrix[i][k]+adjMatrix[k][j]<adjMatrix[i][j])
                    {
                        adjMatrix[i][j]=adjMatrix[i][k]+adjMatrix[k][j];
                    }
                }
            }
        }
        
        cout<<"Shortest distances between all :"<<endl;
        for(int i=0;i<V;i++)
        {
            for(int j=0;j<V;j++)
            {
                if(adjMatrix[i][j]==INT_MAX)
                {
                    cout<<"INF\t";
                }
                else
                {
                    cout << adjMatrix[i][j]<<"\t";
                }
            }
            
            cout<<endl;
        }
    }
    
  
    
    
};

int main()
{
    
    Graph g(4);

    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 10);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 3, 12);
    g.addEdge(2, 3, 2);

    g.floyd();

    return 0;
    
}
