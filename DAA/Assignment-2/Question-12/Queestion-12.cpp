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

    void findEulerCircuit() {
        vector<int> inDegree(V, 0);
        vector<int> outDegree(V, 0);

        for (int u = 0; u < V; u++) {
            for (int v : adj[u]) {
                outDegree[u]++;
                inDegree[v]++;
            }
        }

        // Check if in-degree and out-degree are equal for every vertex
        for (int i = 0; i < V; i++) {
            if (inDegree[i] != outDegree[i]) {
                cout << "Euler circuit does not exist in this graph." << endl;
                return;
            }
        }

        stack<int> circuit;
        stack<int> currentPath;
        int currentVertex = 0; // Start from vertex 0 (you can choose any vertex)

        while (!circuit.empty() || outDegree[currentVertex] != 0) {
            if (outDegree[currentVertex] == 0) {
                circuit.push(currentVertex);
                currentVertex = currentPath.top();
                currentPath.pop();
            } else {
                currentPath.push(currentVertex);
                int nextVertex = adj[currentVertex].back();
                adj[currentVertex].pop_back();
                outDegree[currentVertex]--;
                currentVertex = nextVertex;
            }
        }

        // Print the Euler circuit
        while (!circuit.empty()) {
            cout << circuit.top() << " ";
            circuit.pop();
        }
        cout << endl;
    }
};

int main() {
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    Graph graph(V);

    cout << "Enter the edges (format: source destination):" << endl;
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        graph.addEdge(u, v);
    }

    cout << "Euler Circuit: ";
    graph.findEulerCircuit();

    return 0;
}
