#include <iostream>
#include <vector>
#include <limits>
#include <chrono>

using namespace std;
using namespace chrono;

// Function to calculate the penalty for a given distance traveled
int calculatePenalty(int distance) {
    int targetDistance = 200;
    int diff = targetDistance - distance;
    return diff * diff;
}

// Function to find the optimal sequence of hotels
void optimalHotelSequence(const vector<int>& hotels) {
    int n = hotels.size();

    // dp[i] stores the minimum penalty to reach hotel i
    vector<int> dp(n, numeric_limits<int>::max());

    // Base case: penalty to reach the first hotel
    dp[0] = calculatePenalty(hotels[0]);

    // Dynamic programming to fill the dp array
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            int distance = hotels[i] - hotels[j];
            int penalty = calculatePenalty(distance);
            dp[i] = min(dp[i], dp[j] + penalty);
        }
    }

    // Output the optimal sequence of hotels
    cout << "Optimal sequence of hotels: ";
    int currentHotel = n - 1;
    vector<int> sequence;
    sequence.push_back(currentHotel);

    while (currentHotel > 0) {
        for (int j = currentHotel - 1; j >= 0; --j) {
            int distance = hotels[currentHotel] - hotels[j];
            int penalty = calculatePenalty(distance);
            if (dp[currentHotel] == dp[j] + penalty) {
                currentHotel = j;
                sequence.push_back(currentHotel);
                break;
            }
        }
    }

    // Output the sequence in reverse order
    for (int i = sequence.size() - 1; i >= 0; --i) {
        cout << hotels[sequence[i]] << " ";
    }

    cout << "\nTotal penalty: " << dp[n - 1] << endl;
}

int main() {
    // Input the hotel mileposts
    cout << "Enter the number of hotels: ";
    int numHotels;
    cin >> numHotels;

    vector<int> hotels(numHotels);
    cout << "Enter the mileposts of hotels:\n";
    for (int i = 0; i < numHotels; ++i) {
        cin >> hotels[i];
    }

    // Measure the time taken
    auto start = high_resolution_clock::now();

    // Example usage
    optimalHotelSequence(hotels);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Time taken by function: " << duration.count() << " microseconds" << endl;

    return 0;
}
