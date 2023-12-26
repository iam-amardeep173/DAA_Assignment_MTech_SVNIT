#include <iostream>
#include <vector>
#include <cstdlib>  // For generating random numbers
#include <ctime>    // For seeding the random number generator
#include <chrono>

using namespace std;
using namespace std::chrono;

int maxRevenue(int M, vector<int>& positions, vector<int>& revenues) 
{
    int n = positions.size();
    vector<int> dp(M + 1, 0);

    for (int i = 1; i <= M; i++) {
        dp[i] = dp[i - 1]; // Initialize dp[i] with the previous value
        for (int j = 0; j < n; j++) {
            if (i == positions[j]) {
                // If a billboard can be placed at position i, calculate the revenue
                int prevPos = i - 6;
                if (prevPos < 0) {
                    dp[i] = max(dp[i], revenues[j]);
                } else {
                    dp[i] = max(dp[i], dp[prevPos] + revenues[j]);
                }
            }
        }
    }

    return dp[M];
}

void generateRandomData(int M, vector<int>& positions, vector<int>& revenues, int n) 
{
    srand(static_cast<unsigned>(time(nullptr)));  // Seed the random number generator

    for (int i = 0; i < n; i++) {
        int position = rand() % (M + 1); // Random position between 0 and M
        int revenue = rand() % 10 + 1;   // Random revenue between 1 and 10
        positions.push_back(position);
        revenues.push_back(revenue);
    }
}

int main() 
{
    int M = 20;
    int n = 4; // Change this to the desired number of random billboards
    vector<int> positions;
    vector<int> revenues;

    generateRandomData(M, positions, revenues, n);

    // Measure time duration for finding the result
    auto start_time = high_resolution_clock::now();
    int result = maxRevenue(M, positions, revenues);
    auto end_time = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end_time - start_time).count();

    cout << "Random Positions: ";
    for (int position : positions) {
        cout << position << " ";
    }
    cout << endl;

    cout << "Random Revenues: ";
    for (int revenue : revenues) {
        cout << revenue << " ";
    }
    cout << endl;

    cout << "Maximum total revenue: " << result << endl;
    cout << "Time duration for finding the result: " << duration << " microseconds" << endl;

    return 0;
}