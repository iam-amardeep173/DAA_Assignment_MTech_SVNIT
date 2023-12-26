#include <iostream>
#include <vector>
#include <algorithm> // for max_element
#include <chrono>
#include <cstdlib>   // for rand
#include <ctime>     // for time

using namespace std;
using namespace chrono;

void countingSort(vector<int>& arr) {
    // Find the maximum element in the array
    
    int max_element = *std::max_element(arr.begin(), arr.end());


    // Create a count array to store the count of each element
    vector<int> count(max_element + 1, 0);

    // Count the occurrences of each element in the input array
    for (int num : arr) {
        count[num]++;
    }

    // Modify the count array to store the position of each element
    for (int i = 1; i < count.size(); i++) {
        count[i] += count[i - 1];
    }

    // Create the output array
    vector<int> output(arr.size());

    // Build the output array based on the count array
    for (int i = arr.size() - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Copy the sorted elements back to the original array
    for (int i = 0; i < arr.size(); i++) {
        arr[i] = output[i];
    }
}

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));

    vector<int> arr;
    int size;
    cout << "Enter the size of array: ";
    cin >> size;

    for (int i = 0; i < size; i++) {
        arr.push_back(rand() % size);
    }

    auto start = high_resolution_clock::now();
    countingSort(arr);
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function: " << duration.count() << " microseconds" << endl;

    cout << "Sorted array:";
    for (int num : arr) {
        cout << " " << num;
    }
    cout << endl;

    return 0;
}
