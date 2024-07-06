#include <iostream>
#include <vector>
using namespace std;

class Graph {
    int V; // Vertices
    vector<vector<int>> adj; // Adjacency matrix representation of the graph

    bool isSafe(int v, vector<int>& path, int pos){
        if (adj[path[pos - 1]][v] == 0) return false;

        for (int i = 0; i < pos; i++)
            if (path[i] == v) return false;

        return true;
    }

    bool hamPathUtil(vector<int>& path, int pos){
        if (pos == V) return true;

        for (int v = 0; v < V; v++) {
            if (isSafe(v, path, pos)) {
                path[pos] = v;

                // Recur to construct the rest of the path
                if (hamPathUtil(path, pos + 1)) return true;

                // If adding vertex v doesn't lead to a solution, remove it
                path[pos] = -1;
            }
        }

        return false;
    }

public:
    Graph(int V) { this->V = V, adj.resize(V, vector<int>(V, 0)); } // Constructor

    void addEdge(int u, int v) { adj[u][v] = 1, adj[v][u] = 1;} // Function to add an edge to the graph

    bool hamPath(){
        vector<int> path(V, -1);

        for (int i = 0; i < V; i++) {
            path[0] = i;
            if (hamPathUtil(path, 1)) {
                for (int j = 0; j < V; j++) {
                    cout << path[j] << " ";
                }
                cout << endl;
                return true;
            }
        }
        return false;
    }
};


int main() {
    // Create a graph
    int V,E; cin >> V >> E;
    Graph g(V);
    int u,v;
    for(int i=0; i<E; i++){
        cin>>u>>v;
        g.addEdge(u,v);
    }
    
    // Example below
    // Graph g(5);
    // g.addEdge(0, 1);
    // g.addEdge(0, 3);
    // g.addEdge(1, 2);
    // g.addEdge(1, 3);
    // g.addEdge(1, 4);
    // g.addEdge(2, 4);
    // g.addEdge(3, 4);

    if (!g.hamPath()) {
        cout << "Graph doesn't contain a Hamiltonian Path\n";
    }

    return 0;
}
