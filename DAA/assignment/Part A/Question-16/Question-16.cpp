#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Function to merge two sorted subarrays into one sorted subarray
void merge(vector<int>& ratings, int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;

    // Create temporary arrays
    vector<int> leftArray(n1);
    vector<int> rightArray(n2);

    // Copy data to temporary arrays leftArray[] and rightArray[]
    for (int i = 0; i < n1; i++) {
        leftArray[i] = ratings[left + i];
    }
    for (int i = 0; i < n2; i++) {
        rightArray[i] = ratings[middle + 1 + i];
    }

    // Merge the two sorted arrays back into ratings
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArray[i] <= rightArray[j]) {
            ratings[k] = leftArray[i];
            i++;
        } else {
            ratings[k] = rightArray[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of leftArray[], if any
    while (i < n1) {
        ratings[k] = leftArray[i];
        i++;
        k++;
    }

    // Copy the remaining elements of rightArray[], if any
    while (j < n2) {
        ratings[k] = rightArray[j];
        j++;
        k++;
    }
}

// Function to perform merge sort
void mergeSort(vector<int>& ratings, int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;

        // Sort the first and second halves
        mergeSort(ratings, left, middle);
        mergeSort(ratings, middle + 1, right);

        // Merge the sorted halves
        merge(ratings, left, middle, right);
    }
}

int main() {
    int n;
    cout << "Enter the players (2n): ";
    cin >> n;

    vector<int> ratings(2 * n);
    cout << "Enter the numerical ratings of players: ";
    for (int i = 0; i < 2 * n; i++) {
        cin >> ratings[i];
    }

    auto start = high_resolution_clock::now();

    mergeSort(ratings, 0, 2 * n - 1);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Team A (Top " << n << " players): ";
    for (int i = 0; i < n; i++) {
        cout << ratings[i] << " ";
    }
    cout << endl;

    cout << "Team B : ";
    for (int i = n; i < 2 * n; i++) {
        cout << ratings[i] << " ";
    }
    cout << endl;

    cout << "Time taken by function: " << duration.count() << " microseconds" << endl;

    return 0;
}
