#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Graph {
public:
    int V;
    vector<vector<int>> adj;

    Graph(int vertices) {
        V = vertices;
        adj.resize(V);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    void topologicalSortDFS(int v, vector<bool>& visited, stack<int>& s) {
        visited[v] = true;

        for (int neighbor : adj[v]) {
            if (!visited[neighbor]) {
                topologicalSortDFS(neighbor, visited, s);
            }
        }

        s.push(v);
    }

    void topologicalSort() {
        vector<bool> visited(V, false);
        stack<int> s;

        for (int i = 0; i < V; ++i) {
            if (!visited[i]) {
                topologicalSortDFS(i, visited, s);
            }
        }

        cout << "Topological Sort: ";
        while (!s.empty()) {
            cout << s.top() << " ";
            s.pop();
        }
        cout << endl;
    }
};

int main() {
    Graph g(6);

    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    g.topologicalSort();

    return 0;
}
