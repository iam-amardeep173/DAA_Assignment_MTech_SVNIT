#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

vector<vector<int>> adj;
int N;
vector<int> color; // Store the color of each vertex

void make_graph() {
    cout << "Enter N (nodes):\n";
    cin >> N;

    color.resize(N, 0); // Initialize colors to 0 (unassigned)

    for (int i = 0; i < N; i++) {
        vector<int> temp;
        adj.push_back(temp);
    }

    cout << "Enter edges: (-1) to exit\n";
    while (1) {
        int from, to;
        cin >> from;
        if (from == -1)
            break;
        cin >> to;
        if (to == -1)
            break;
        adj[from - 1].push_back(to - 1);
        adj[to - 1].push_back(from - 1);
    }
}

bool util(int current, int c) {
    if (color[current] != 0)
        return color[current] == c;

    color[current] = c;
    for (int neighbor : adj[current]) {
        if (!util(neighbor, 3 - c)) // Alternates between 1 and 2
            return false;
    }
    return true;
}

bool check_coloring() {
    for (int i = 0; i < N; i++) {
        if (color[i] == 0) {
            if (!util(i, 1)) {
                return false; // Graph is not 2-colorable
            }
        }
    }
    return true; // Graph is 2-colorable
}

int main() {
    make_graph();

    auto start = high_resolution_clock::now();

    // Coloring the graph
    if (check_coloring()) {
        cout << "The graph is 2-colorable (bipartite).\n";
    } else {
        cout << "The graph is not 2-colorable (not bipartite).\n";
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);

    cout << "Time taken: " << duration.count() << " nanoseconds" << endl;

    return 0;
}
