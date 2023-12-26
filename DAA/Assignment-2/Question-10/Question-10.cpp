#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

using namespace std;

int minBaseStations(vector<int>& houses) {
    int n = houses.size();
    sort(houses.begin(), houses.end());  // Sort houses in ascending order

    int result = 0;  // Initialize the number of base stations

    int i = 0;  // Initialize the current house under consideration

    while (i < n) {
        // Find the rightmost house that is within four miles
        int candidate = houses[i];

        // Increment the result to count the base station
        result++;

        // Move to the next house that is at least four miles to the right
        while (i < n && houses[i] - candidate <= 4) {
            i++;
        }
        
        // Move to the next house that is at least four miles to the right
        if (i < n) {
            candidate = houses[i];
            while (i < n && houses[i] - candidate <= 4) {
                i++;
            }
        }
    }

    return result;
}

int main() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> distribution(1, 100);

    int n = 200;  // Number of houses

    vector<int> houses(n);
    for (int i = 0; i < n; i++) {
        houses[i] = distribution(gen);  // Generate random house positions
    }

    auto start = chrono::high_resolution_clock::now();  // Start measuring time

    int baseStations = minBaseStations(houses);

    auto end = chrono::high_resolution_clock::now();  // Stop measuring time
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);

    cout << "House positions along the road: ";
    for (int i = 0; i < n; i++) {
        cout << houses[i] << " ";
    }
    cout << endl;

    cout << "Minimum number of base stations needed: " << baseStations << endl;
    cout << "Time taken by the algorithm: " << duration.count() << " microseconds" << endl;

    return 0;
}
