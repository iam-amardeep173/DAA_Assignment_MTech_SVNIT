#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
using namespace std;
using namespace std::chrono;

struct Item {
    int weight;
    int value;
};

std::vector<Item> generateDataset(int size) {
    std::vector<Item> items;

    for (int i = 0; i < size; i++) {
        Item newItem;
        newItem.value = i + 1;   // Generating increasing values
        newItem.weight = size - i; // Generating decreasing weights
        items.push_back(newItem);
    }

    // Sort the items using insertion sort based on value-to-weight ratio
    for (int i = 1; i < size; i++) {
        Item key = items[i];
        int j = i - 1;

        while (j >= 0 && (static_cast<double>(items[j].value) / items[j].weight) < (static_cast<double>(key.value) / key.weight)) {
            items[j + 1] = items[j];
            j = j - 1;
        }
        items[j + 1] = key;
    }

    return items;
}

int knapsack(int n, int m, vector<Item>& items) {
    int max_value = 0;
    int current_weight = 0;

    for (int i = 0; i < n; i++) {
        if (current_weight + items[i].weight <= m) {
            // Include the entire item in the knapsack.
            max_value += items[i].value;
            current_weight += items[i].weight;
        } else {
            // Include a fraction of the item to maximize value.
            int remaining_capacity = m - current_weight;
            max_value += static_cast<int>(items[i].value * (static_cast<double>(remaining_capacity) / items[i].weight));
            break;
        }
    }

    return max_value;
}

int main() {
    int n, m;
    cout << "Enter the number of objects: ";
    cin >> n;

    cout << "Enter the capacity of the knapsack: ";
    cin >> m;

    vector<Item> items = generateDataset(n); // Call generateDataset to populate the items vector

    // Print the sorted items (values in increasing order, weights in decreasing order)
    for (const Item& item : items) {
        cout << "Value: " << item.value << ", Weight: " << item.weight << endl;
    }

    auto start = high_resolution_clock::now();
    int max_value = knapsack(n, m, items);
    auto end = high_resolution_clock::now();

    cout << "The maximum value that can be obtained is: " << max_value << endl;
    cout << "Time taken: " << duration_cast<nanoseconds>(end - start).count() << " nanoseconds" << endl;

    return 0;
}
