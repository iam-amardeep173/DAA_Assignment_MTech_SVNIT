#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include<time.h>
#include<sys/time.h>
#include<chrono>

using namespace std;

// Merge two sorted subarrays
void merge(vector<int>& players, int low, int mid, int high) {
    int n1 = mid - low + 1;
    int n2 = high - mid;

    vector<int> left(n1);
    vector<int> right(n2);

    for (int i = 0; i < n1; i++) {
        left[i] = players[low + i];
    }

    for (int i = 0; i < n2; i++) {
        right[i] = players[mid + 1 + i];
    }

    int i = 0, j = 0, k = low;

    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            players[k] = left[i];
            i++;
        } else {
            players[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        players[k] = left[i];
        i++;
        k++;
    }

    while (j < n2) {
        players[k] = right[j];
        j++;
        k++;
    }
}

// Merge sort function
void mergeSort(vector<int>& players, int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;
        mergeSort(players, low, mid);
        mergeSort(players, mid + 1, high);
        merge(players, low, mid, high);
    }
}

// Function to partition players into two teams
void partitionTeams(vector<int>& players) {
    int n = players.size() / 2; // Number of players in each team

    mergeSort(players, 0, 2 * n - 1); // Sort players using merge sort

    vector<int> teamA, teamB;

    for (int i = 0; i < 2 * n; i++) {
        if (i < n)
            teamA.push_back(players[i]);
        else
            teamB.push_back(players[i]);
    }

    // Print the two teams
    cout << "Team A: ";
    for (int player : teamA) {
        cout << player << " ";
    }
    cout << endl;

    cout << "Team B: ";
    for (int player : teamB) {
        cout << player << " ";
    }
    cout << endl;
}

int main() {
    // Generate random player ratings for testing
    srand(time(0));
    int n;
    cout << "Enter the number of players (2n): ";
    cin >> n;

    vector<int> players(2 * n);

    for (int i = 0; i < 2 * n; i++) {
        players[i] = rand() % 100; // Generate random ratings between 0 and 99
    }
     
	auto start = chrono::high_resolution_clock::now();	
	// Partition the teams
	partitionTeams(players);
	auto stop = chrono::high_resolution_clock::now();
        long long int time = chrono::duration_cast<chrono::nanoseconds>(stop - start).count(); 
        cout << time*1000 << " microseconds";

    return 0;
}
