#include<bits/stdc++.h>

using namespace std;
using namespace chrono;


// Function to generate a random array with elements in the range [min, max]
vector<int> generateRandomArray(int size) {
    
	srand(0);
    vector<int> arr(size);
    for (int &num : arr) {
        num = rand()%size;
    }

    return arr;
}

// Function to partition the array and return the pivot index (Lomuto partition scheme)
int lomutoPartition(vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // Choose the last element as the pivot
    int i = low - 1; // Index of the smaller element

    for (int j = low; j < high; j++) {
        // If the current element is smaller than the pivot
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    // Swap the pivot element with the element at (i + 1)
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Function to perform quicksort using Lomuto partition
void lomutoQuicksort(vector<int>& arr, int low, int high) {
    if (low < high) {
        // Find the partition index
        int pivotIndex = lomutoPartition(arr, low, high);

        // Recursively sort the subarrays
        lomutoQuicksort(arr, low, pivotIndex - 1);
        lomutoQuicksort(arr, pivotIndex + 1, high);
    }
}

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // Choose the last element as the pivot
    int i = low - 1; // Index of the smaller element

    for (int j = low; j < high; j++) {
        // If the current element is smaller than or equal to the pivot
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    // Swap the pivot element with the element at (i + 1)
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quicksort(vector<int>& arr, int low, int high) {
    if (low < high) {
        // Find the partition index
        int pivotIndex = partition(arr, low, high);

        // Recursively sort the subarrays
        quicksort(arr, low, pivotIndex - 1);
        quicksort(arr, pivotIndex + 1, high);
    }
}

// Utility function to print an array
void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

// ... (Previous code remains unchanged)

int main() {
    int size ; // You can adjust the size of the array
    cout<<"Enter the size of array : ";
    cin>>size;

    vector<int> arr = generateRandomArray(size);
	cout<<"Array before sorting :"<<endl;
    // Measure the time taken by lomutoQuicksort
    printArray(arr);
    auto startLomuto = high_resolution_clock::now();
    lomutoQuicksort(arr, 0, size - 1);
    auto stopLomuto = high_resolution_clock::now();
    auto durationLomuto = duration_cast<microseconds>(stopLomuto - startLomuto);
    cout<<"Array after sorting :"<<endl;
    printArray(arr);

    cout << "\n\tTime taken by Quicksort (version 1): " << durationLomuto.count() << " microseconds" << endl;

    // Restore the original unsorted array
    arr = generateRandomArray(size);
    cout<<"Array before sorting :"<<endl;
	printArray(arr);
    // Measure the time taken by quicksort
    auto startQuicksort = high_resolution_clock::now();
    quicksort(arr, 0, size - 1);
    auto stopQuicksort = high_resolution_clock::now();
    auto durationQuicksort = duration_cast<microseconds>(stopQuicksort - startQuicksort);
    cout<<"Array after sorting :"<<endl;
    printArray(arr);

    cout << "\n\tTime taken by quicksort (version 2): " << durationQuicksort.count() << " microseconds" << endl;

    return 0;
}

