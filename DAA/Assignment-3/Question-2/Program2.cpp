#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;
// Function to generate a random integer between a given range
int getRandomValue(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to count inversions in an array using the brute force approach
int countInversions_brute(int arr[], int n) {
    int inversionCount = 0;

    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (arr[i] > arr[j]) {
                inversionCount++;
            }
        }
    }

    return inversionCount;
}

// Function to merge two sorted arrays and count inversions
int mergeAndCount(int arr[], int temp[], int left, int mid, int right) {
    int i = left;       // Index for the left subarray
    int j = mid + 1;    // Index for the right subarray
    int k = left;       // Index for the merged array
    int inversionCount = 0;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            // Inversion found
            temp[k++] = arr[j++];
            inversionCount += (mid - i + 1);
        }
    }

    // Copy the remaining elements of the left subarray
    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    // Copy the remaining elements of the right subarray
    while (j <= right) {
        temp[k++] = arr[j++];
    }

    // Copy the merged array back to the original array
    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
    }

    return inversionCount;
}

// Function to recursively count inversions using merge-sort
int mergeSortAndCount(int arr[], int temp[], int left, int right) {
    int inversionCount = 0;

    if (left < right) {
        int mid = (left + right) / 2;

        // Count inversions in the left subarray
        inversionCount += mergeSortAndCount(arr, temp, left, mid);

        // Count inversions in the right subarray
        inversionCount += mergeSortAndCount(arr, temp, mid + 1, right);

        // Merge the two sorted subarrays and count inversions
        inversionCount += mergeAndCount(arr, temp, left, mid, right);
    }

    return inversionCount;
}

// Function to initialize the merge-sort process
int countInversions(int arr[], int n) {
    int* temp = new int[n]; // Temporary array for merging
    int inversionCount = mergeSortAndCount(arr, temp, 0, n - 1);
    delete[] temp;
    return inversionCount;
}

int main() {
    // Seed the random number generator with the current time
    srand(static_cast<unsigned int>(time(nullptr)));

    // Example usage:
    cout<<"Enter the no. of element in array (size) : ";
    int n ; // Adjust the size of the array as needed
    cin>>n;
    int arr[n];

    // Generate random values for the array
    for (int i = 0; i < n; ++i) {
        arr[i] = getRandomValue(1, n);
    }

    // Output the generated array
    cout << "Generated array: ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Measure the execution time of the brute force approach
    auto start_brute = chrono::high_resolution_clock::now();
    int inversions_brute = countInversions_brute(arr, n);
    auto end_brute = chrono::high_resolution_clock::now();

    // Output the result and execution time
    cout << "Number of inversions using Brute Force: " << inversions_brute << endl;
    auto duration_brute = chrono::duration_cast<chrono::microseconds>(end_brute - start_brute);
    cout << "\tExecution time (Brute Force): " << duration_brute.count() << " microseconds" << endl;

    // Measure the execution time of the merge-sort approach
    auto start_merge = chrono::high_resolution_clock::now();
    int inversions_merge = countInversions(arr, n);
    auto end_merge = chrono::high_resolution_clock::now();

    // Output the result and execution time
    cout << "Number of inversions using Merge and Count: " << inversions_merge << endl;
    auto duration_merge = chrono::duration_cast<chrono::microseconds>(end_merge - start_merge);
    cout << "\tExecution time (Merge and Count): " << duration_merge.count() << " microseconds" << endl;

    return 0;
}

