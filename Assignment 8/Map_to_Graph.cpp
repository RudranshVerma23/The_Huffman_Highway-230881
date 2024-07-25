#include <bits/stdc++.h>
using namespace std;

struct Edge {
    string destination;
    int distance;
};

class Graph {
public:
    void addNode(const string& node) {
        directConnection[node] = vector<Edge>();
    }

    void addEdge(const string& source, const string& destination, int distance) {
        directConnection[source].push_back({destination, distance});
        directConnection[destination].push_back({source, distance});
    }

    void printGraph() const {
        for (const auto& pair : directConnection) {
            cout << pair.first << ": ";
            for (const auto& edge : pair.second) {
                cout << "(" << edge.destination << ", " << edge.distance << ") ";
            }
            cout << endl;
        }
    }

private:
    unordered_map<string, vector<Edge>> directConnection;
};

int main() {
    Graph g;

    g.addNode("Hall 1");
    g.addNode("Hall 2");
    g.addNode("Hall 3");
    g.addNode("Hall 4");
    g.addNode("Hall 5");
    g.addNode("Hall 6");
    g.addNode("Hall 7");
    g.addNode("Hall 8");
    g.addNode("Hall 9");
    g.addNode("Hall 10");
    g.addNode("Hall 11");
    g.addNode("Hall 12");
    g.addNode("Hall 13");
    g.addNode("Girls Hostel 1");
    g.addNode("Counselling Service");
    g.addNode("Kargil Chowk");
    g.addNode("Open Air Theatre");
    g.addNode("New Shopping Complex");
    g.addNode("Pronite Ground");
    g.addNode("Health Centre");
    g.addNode("Events Ground");

    g.addEdge("Hall 1", "Hall 2", 75);
    g.addEdge("Hall 1", "Hall 5", 89);
    g.addEdge("Hall 1", "Hall 3", 175);
    g.addEdge("Hall 2", "Hall 12", 460);
    g.addEdge("Hall 2", "Kargil Chowk", 420);
    g.addEdge("Hall 2", "Girls Hostel 1", 420);
    g.addEdge("Hall 3", "Girls Hostel 1", 170);
    g.addEdge("Hall 3", "Hall 5", 188);
    g.addEdge("Hall 3", "Hall 4", 100);
    g.addEdge("Hall 4", "New Shopping Complex", 220);
    g.addEdge("Hall 4", "Hall 13", 683);
    g.addEdge("Hall 4", "Hall 9", 763);
    g.addEdge("Hall 4", "Open Air Theatre", 300);
    g.addEdge("New Shopping Complex", "Pronite Ground", 80);
    g.addEdge("New Shopping Complex", "Health Centre", 300);
    g.addEdge("Hall 5", "Hall 13", 515);
    g.addEdge("Hall 5", "Hall 9", 595);
    g.addEdge("Hall 5", "Hall 7", 415);
    g.addEdge("Hall 6", "Health Centre", 100);
    g.addEdge("Hall 6", "Counselling Service", 200);
    g.addEdge("Hall 7", "Hall 8", 80);
    g.addEdge("Hall 7", "Hall 10", 205);
    g.addEdge("Hall 7", "Hall 13", 540);
    g.addEdge("Hall 7", "Hall 9", 620);
    g.addEdge("Hall 8", "Hall 10", 225);
    g.addEdge("Hall 8", "Open Air Theatre", 80);
    g.addEdge("Hall 8", "Events Ground", 80);
    g.addEdge("Events Ground", "Pronite Ground", 160);
    g.addEdge("Events Ground", "Hall 11", 160);
    g.addEdge("Hall 9", "Hall 10", 180);
    g.addEdge("Hall 10", "Hall 11", 200);
    g.addEdge("Hall 12", "Hall 13", 150);
    g.addEdge("Girls Hostel 1", "Kargil Chowk", 500);
    g.addEdge("Girls Hostel 1", "Health Centre", 345);
    g.addEdge("Girls Hostel 1", "Counselling Service", 390);
    g.addEdge("Counselling Service", "Kargil Chowk", 390);

    // Print the graph
    g.printGraph();

    return 0;
}