#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm> // For sorting

using namespace std;

// Define a class for the graph
class Graph {
public:
    // Constructor
    Graph() {}

    // Add an edge to the graph
    void addEdge(char u, char v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u); // Since it's an undirected graph
    }

    // Depth-First Search
    void DFS(char v, unordered_set<char>& visited) {
        visited.insert(v);
        for (char neighbor : adjList[v]) {
            if (visited.find(neighbor) == visited.end()) {
                DFS(neighbor, visited);
            }
        }
    }

    // Count the number of connected components and return their sizes
    vector<int> getConnectedComponentSizes() {
        unordered_set<char> visited;
        vector<int> componentSizes;

        for (auto kvp : adjList) {
            char vertex = kvp.first;
            if (visited.find(vertex) == visited.end()) {
                int componentSize = DFSAndGetConnectedComponentSize(vertex, visited);
                componentSizes.push_back(componentSize);
            }
        }

        sort(componentSizes.rbegin(), componentSizes.rend()); // Sort in descending order
        return componentSizes;
    }

private:
    unordered_map<char, vector<char>> adjList;

    // Modified DFS to return the size of the connected component
    int DFSAndGetConnectedComponentSize(char v, unordered_set<char>& visited) {
        visited.insert(v);
        int size = 1; // Initialize component size

        for (char neighbor : adjList[v]) {
            if (visited.find(neighbor) == visited.end()) {
                size += DFSAndGetConnectedComponentSize(neighbor, visited);
            }
        }

        return size;
    }
};

int main() {
    Graph graph;

    // Input vertices and edges
    char input;
    while (cin >> input && input != 'e') {
        char vertex = input;
        while (cin >> input && input != 'e' && input != 'v') {
            char edge = input;
            graph.addEdge(vertex, edge);
        }
    }

    // Calculate the number of connected components and their sizes
    vector<int> componentSizes = graph.getConnectedComponentSizes();
    int numComponents = componentSizes.size();

    // Output the number of components
    cout << "Number of connected components: " << numComponents << endl;

    // Output the sorted list of component sizes
    cout << "Component sizes (sorted from largest to smallest): ";
    for (int size : componentSizes) {
        cout << size << " ";
    }
    cout << endl;

    return 0;
}
