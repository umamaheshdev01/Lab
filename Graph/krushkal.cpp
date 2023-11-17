#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int src,dest,weight;
};

struct Subset
{
    int parent,rank;
};

bool compareEdges(const Edge &a,const Edge &b)
{
    return a.weight<b.weight;
};

int find(Subset subsets[],int i)
{
    if(subsets[i].parent != i)
    {
        subsets[i].parent = find(subsets,subsets[i].parent);
    }
    
    return subsets[i].parent;
}

void unionSets(Subset subsets[],int x,int y)
{
    int rootX = find(subsets,x);
    int rootY = find(subsets,y);
    
    if(subsets[rootX].rank < subsets[rootY].rank)
    {
        subsets[rootX].parent = rootY;
    }
    else if(subsets[rootX].rank > subsets[rootY].rank)
    {
        subsets[rootY].parent = rootX;
    }
    else
    {
        subsets[rootX].parent = rootY;
        subsets[rootY].rank++;
    }
}


void kruskal(vector<Edge> &edges,int V,int E)
{
    sort(edges.begin(),edges.end(),compareEdges);
    
    Subset * subsets = new Subset[V];
    
    for(int i=0;i<V;i++)
    {
       subsets[i].parent = i;
       subsets[i].rank = 0;
    }
    
    vector<Edge> result;
    
    for(int i=0;i<E;i++)
    {
        int x  = find(subsets,edges[i].src);
        int y = find(subsets,edges[i].dest);
        
        if(x!=y)
        {
            result.push_back(edges[i]);
            unionSets(subsets,x,y);
        }
    }
    
    
    cout<<"The minnimum spanning tree:"<<endl;
    
    for(auto x : result)
    {
        cout<<x.src<<"------>"<<x.dest<<" : "<<x.weight<<endl;
    }
    
    delete[] subsets;
}

int main()
{
    int V = 4; 
    int E = 5; 

    vector<Edge> edges = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    kruskal(edges, V, E);

}


