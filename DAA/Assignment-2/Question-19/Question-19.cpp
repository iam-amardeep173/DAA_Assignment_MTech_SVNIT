#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Define a structure to represent edges
struct Edge {
    int src, dest, weight;
};

// Define a class for a graph
class Graph {
public:
    int V, E;
    vector<Edge> edges;

    Graph(int V, int E) {
        this->V = V;
        this->E = E;
    }

    // Function to add an edge to the graph
    void addEdge(int src, int dest, int weight) {
        Edge edge = {src, dest, weight};
        edges.push_back(edge);
    }
};

// Kruskal's algorithm to find MST
class Kruskal {
public:
    static bool compareEdges(Edge a, Edge b) {
        return a.weight < b.weight;
    }

    vector<Edge> findMST(Graph graph) {
        vector<Edge> result;
        sort(graph.edges.begin(), graph.edges.end(), compareEdges);
        vector<int> parent(graph.V, -1);

        for (Edge edge : graph.edges) {
            int x = find(parent, edge.src);
            int y = find(parent, edge.dest);

            if (x != y) {
                result.push_back(edge);
                unionSets(parent, x, y);
            }
        }

        return result;
    }

    int find(vector<int> &parent, int i) {
        if (parent[i] == -1)
            return i;
        return find(parent, parent[i]);
    }

    void unionSets(vector<int> &parent, int x, int y) {
        int xset = find(parent, x);
        int yset = find(parent, y);
        parent[xset] = yset;
    }
};

// Prim's algorithm to find MST
class Prim {
public:
    vector<Edge> findMST(Graph graph) {
        vector<Edge> result;
        vector<int> key(graph.V, INT_MAX);
        vector<bool> mstSet(graph.V, false);

        key[0] = 0;
        for (int i = 0; i < graph.V - 1; i++) {
            int u = minKey(key, mstSet, graph.V);
            mstSet[u] = true;

            for (Edge edge : graph.edges) {
                if (!mstSet[edge.dest] && edge.weight < key[edge.dest]) {
                    key[edge.dest] = edge.weight;
                }
            }
        }

        for (int i = 1; i < graph.V; i++) {
            for (Edge edge : graph.edges) {
                if (edge.src == i && edge.dest == i) {
                    result.push_back(edge);
                }
            }
        }

        return result;
    }

    int minKey(vector<int> key, vector<bool> mstSet, int V) {
        int min = INT_MAX, min_index;

        for (int v = 0; v < V; v++) {
            if (!mstSet[v] && key[v] < min) {
                min = key[v];
                min_index = v;
            }
        }

        return min_index;
    }
};

int main() {
    srand(time(0));

    // You can adjust these parameters to experiment with different graph sizes and densities.
    int graphSizes[] = {100, 200, 300};
    double densities[] = {0.2, 0.4, 0.6};

    for (int size : graphSizes) {
        for (double density : densities) {
            int V = size;
            int E = static_cast<int>(density * V * (V - 1) / 2);
            Graph graph(V, E);

            // Generate random edges
            for (int i = 0; i < E; i++) {
                int src = rand() % V;
                int dest = rand() % V;
                int weight = rand() % 1000;
                graph.addEdge(src, dest, weight);
            }

            Kruskal kruskal;
            Prim prim;

            // Measure the time taken by Kruskal's algorithm
            auto kruskal_start = high_resolution_clock::now();
            kruskal.findMST(graph);
            auto kruskal_stop = high_resolution_clock::now();
            auto kruskal_duration = duration_cast<milliseconds>(kruskal_stop - kruskal_start);

            // Measure the time taken by Prim's algorithm
            auto prim_start = high_resolution_clock::now();
            prim.findMST(graph);
            auto prim_stop = high_resolution_clock::now();
            auto prim_duration = duration_cast<milliseconds>(prim_stop - prim_start);

            cout << "Graph Size: " << V << ", Density: " << density << endl;
            cout << "Kruskal's Algorithm Time: " << kruskal_duration.count() << " ms" << endl;
            cout << "Prim's Algorithm Time: " << prim_duration.count() << " ms" << endl;
            cout << "------------------------" << endl;
        }
    }

    return 0;
}
