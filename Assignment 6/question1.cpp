#include <bits/stdc++.h>
#define pb push_back

using namespace std;
 
// A directed graph using
// adjacency list representation
class Graph {
    int v; // Vertices
    list<int>* adj; // Adjacency list

    void printAllPathsUtil(int u, int d, bool vis[],int path[], int& path_index){
        vis[u] = true;
        path[path_index] = u;
        path_index++;

        if (u == d) {
            for (int i = 0; i < path_index; i++) cout << path[i] << " ";
            cout << endl;
        }
        else {
            for (auto i = adj[u].begin(); i != adj[u].end(); ++i)
                if (vis[*i] ^ 1)
                    printAllPathsUtil(*i, d, vis, path, path_index);
        }
        // to clear the index and visited array for next path
        path_index--;
        vis[u] = false;
    }
 
public:
    Graph(int v) { this->v = v, adj = new list<int>[v]; } //Constructor
    void addEdge(int u, int v) { adj[u].pb(v); }

    void printAllPaths(int s, int d) {

        bool* vis = new bool[v];
    
        int* path = new int[v];
        int path_index = 0;

        for (int i = 0; i < v; i++) vis[i] = false;
    
        printAllPathsUtil(s, d, vis, path, path_index);
    }
};


int main(){
    
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(2, 0);
    g.addEdge(2, 1);
    g.addEdge(1, 3);
 
    int s = 2, d = 3;
    cout << "Following are all different paths from " << s
         << " to " << d << endl;
    g.printAllPaths(s, d);
 
    return 0;
}