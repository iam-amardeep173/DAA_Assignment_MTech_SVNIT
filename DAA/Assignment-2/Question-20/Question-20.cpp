#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <random>
#include <cfloat>
#include <chrono>

using namespace std;

struct Village {
    double x, y;
};

double distance(const Village& v1, const Village& v2) {
    double dx = v1.x - v2.x;
    double dy = v1.y - v2.y;
    return sqrt(dx * dx + dy * dy);
}

double findMinimumSpanningTree(const vector<Village>& villages) {
    int n = villages.size();

    vector<bool> visited(n, false);
    vector<double> minDistance(n, DBL_MAX);
    minDistance[0] = 0.0;
    double totalDistance = 0.0;

    for (int i = 0; i < n; ++i) {
        int u = -1;
        for (int j = 0; j < n; ++j) {
            if (!visited[j] && (u == -1 || minDistance[j] < minDistance[u]))
                u = j;
        }

        visited[u] = true;
        totalDistance += minDistance[u];

        for (int v = 0; v < n; ++v) {
            if (!visited[v]) {
                double dist = distance(villages[u], villages[v]);
                minDistance[v] = min(minDistance[v], dist);
            }
        }
    }

    return totalDistance;
}

vector<Village> generateRandomVillages(int n) {
    vector<Village> villages;
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<double> dist(0.0, 1.0);

    for (int i = 0; i < n; ++i) {
        Village v;
        v.x = dist(gen);
        v.y = dist(gen);
        villages.push_back(v);
    }

    return villages;
}

int main() {
    int numVillages = 50; // Number of villages
    vector<Village> villages = generateRandomVillages(numVillages);

    auto start = chrono::high_resolution_clock::now();

    double totalDistance = findMinimumSpanningTree(villages);

    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);

    cout << "Total minimum distance to connect all villages: " << totalDistance << endl;
    cout << "Time taken: " << duration.count() << " microseconds" << endl;

    return 0;
}
