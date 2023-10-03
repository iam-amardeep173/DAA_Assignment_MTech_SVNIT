#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>

using namespace std;

vector<int> generateDataset(int size) {
    vector<int> dataset;
    srand(time(nullptr));

    for (int i = 0; i < size; i++) {
        int randValue = rand() % INT_MAX + 1;
        dataset.push_back(randValue);
    }

    return dataset;
}

int insertionSort(vector<int>& arr) {
    int swaps = 0;
    for (int i = 1; i < arr.size(); i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
            swaps++;
        }
        arr[j + 1] = key;
    }
    return swaps;
}

int merge(vector<int>& arr, vector<int>& temp, int left, int mid, int right) {
    int swaps = 0;
    int i = left, j = mid + 1, k = left;
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            swaps += (mid - i + 1); // Count swaps
        }
    }
    while (i <= mid) {
        temp[k++] = arr[i++];
    }
    while (j <= right) {
        temp[k++] = arr[j++];
    }
    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
    }
    return swaps;
}

int mergeSortHelper(vector<int>& arr, vector<int>& temp, int left, int right) {
    int swaps = 0;
    if (left < right) {
        int mid = (left + right) / 2;
        swaps += mergeSortHelper(arr, temp, left, mid);
        swaps += mergeSortHelper(arr, temp, mid + 1, right);
        swaps += merge(arr, temp, left, mid, right);
    }
    return swaps;
}

int mergeSort(vector<int>& arr) {
    vector<int> temp(arr.size());
    return mergeSortHelper(arr, temp, 0, arr.size() - 1);
}

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

int quickSortHelper(vector<int>& arr, int low, int high) {
    int swaps = 0;
    if (low < high) {
        int pivotIndex = partition(arr, low, high);
        swaps += (pivotIndex - low) + (high - pivotIndex);
        swaps += quickSortHelper(arr, low, pivotIndex - 1);
        swaps += quickSortHelper(arr, pivotIndex + 1, high);
    }
    return swaps;
}

int quickSort(vector<int>& arr) {
    return quickSortHelper(arr, 0, arr.size() - 1);
}

int heapify(vector<int>& arr, int n, int i) {
    int swaps = 0;
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(arr[i], arr[largest]);
        swaps++;
        swaps += heapify(arr, n, largest);
    }

    return swaps;
}

int heapSort(vector<int>& arr) {
    int swaps = 0;
    int n = arr.size();

    for (int i = n / 2 - 1; i >= 0; i--) {
        swaps += heapify(arr, n, i);
    }

    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        swaps += heapify(arr, i, 0);
    }

    return swaps;
}

int main() {
    vector<int> unsortedDataset = generateDataset(100000);
    vector<int> sortedDataset = unsortedDataset;
    sort(sortedDataset.begin(), sortedDataset.end());

    cout << "Testing on unsorted data:" << endl;
    cout << "Insertion Sort - Unsorted Data:" << endl;
    cout << "Swaps: " << insertionSort(unsortedDataset) << endl;
    cout << "Merge Sort - Unsorted Data:" << endl;
    cout << "Swaps: " << mergeSort(unsortedDataset) << endl;
    cout << "Quick Sort - Unsorted Data:" << endl;
    cout << "Swaps: " << quickSort(unsortedDataset) << endl;
    cout << "Heap Sort - Unsorted Data:" << endl;
    cout << "Swaps: " << heapSort(unsortedDataset) << endl;

    cout << "\nTesting on sorted data:" << endl;
    cout << "Insertion Sort - Sorted Data:" << endl;
    cout << "Swaps: " << insertionSort(sortedDataset) << endl;
    cout << "Merge Sort - Sorted Data:" << endl;
    cout << "Swaps: " << mergeSort(sortedDataset) << endl;
    cout << "Quick Sort - Sorted Data:" << endl;
    cout << "Swaps: " << quickSort(sortedDataset) << endl;
    cout << "Heap Sort - Sorted Data:" << endl;
    cout << "Swaps: " << heapSort(sortedDataset) << endl;

    return 0;
}
