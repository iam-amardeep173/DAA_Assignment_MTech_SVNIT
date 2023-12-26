#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v;
    double weight;

    Edge(int from, int to, double w) : u(from), v(to), weight(w) {}

    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

int main() {
    vector<pair<double, double>> villages = {{0, 0}, {1, 0}, {0, 1}, {1, 1}};
    int numVillages = villages.size();

    vector<Edge> edges;

    // Calculate distances and create edges
    for (int i = 0; i < numVillages; i++) {
        for (int j = i + 1; j < numVillages; j++) {
            double distance = sqrt(pow(villages[i].first - villages[j].first, 2) + pow(villages[i].second - villages[j].second, 2));
            edges.push_back(Edge(i, j, distance));
        }
    }

    // Sort edges by weight
    sort(edges.begin(), edges.end());

    vector<Edge> minimumSpanningTree;
    vector<int> parent(numVillages);

    // Initialize parent array
    for (int i = 0; i < numVillages; i++) {
        parent[i] = i;
    }

    // Kruskal's algorithm to find MST
    for (Edge edge : edges) {
        int rootU = parent[edge.u];
        int rootV = parent[edge.v];
        if (rootU != rootV) {
            minimumSpanningTree.push_back(edge);
            for (int i = 0; i < numVillages; i++) {
                if (parent[i] == rootV) {
                    parent[i] = rootU;
                }
            }
        }
    }

    // Output the minimum spanning tree edges
    cout << "Shortest network of roads (Minimum Spanning Tree):" << endl;
    for (Edge edge : minimumSpanningTree) {
        cout << "Connect village " << edge.u << " to village " << edge.v << " with distance " << edge.weight << endl;
    }

    return 0;
}
