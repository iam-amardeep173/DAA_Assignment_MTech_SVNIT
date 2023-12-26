#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <ctime>
using namespace std;
using namespace std::chrono;

struct Item {
    int weight;
    int value;
};

bool compareItems(const Item& item1, const Item& item2) {
    double ratio1 = static_cast<double>(item1.value) / item1.weight;
    double ratio2 = static_cast<double>(item2.value) / item2.weight;
    return ratio1 > ratio2;
}

vector<Item> generateDataset(int size) {
    vector<Item> items;
    srand(time(0));
    for (int i = 0; i < size; i++) {
        Item newItem;
        newItem.value = rand() % 100;
        newItem.weight = 10;
        items.push_back(newItem);
        cout << newItem.value << " " << newItem.weight << endl;
    }
        // Sort the items in insertion sort 
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

    // Iterate over the items and add them to the knapsack if there is enough capacity (greedy step).
    for (int i = 0; i < n; i++) {
        if (current_weight + items[i].weight <= m) {
            max_value += items[i].value;
            current_weight += items[i].weight;
        } else {
            // If adding the entire item would exceed the capacity, add a fraction.
            double remaining_capacity = m - current_weight;
            max_value += (remaining_capacity / items[i].weight) * items[i].value;
            break; // Break out of the loop since the knapsack is full.
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

    vector<Item> items = generateDataset(n);

    auto start = high_resolution_clock::now();
    int max_value = knapsack(n, m, items);
    auto end = high_resolution_clock::now();

    cout << "The maximum value that can be obtained is: " << max_value << endl;
    cout << "Time taken: " << duration_cast<nanoseconds>(end - start).count() << " nanoseconds" << endl;


    return 0;
}
