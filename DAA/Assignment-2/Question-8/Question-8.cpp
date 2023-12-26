#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>  // For measuring time

using namespace std;
using namespace std::chrono;

struct Item {
    int weight, profit;
    double profitDensity;
};

bool compareItems(Item a, Item b) {
    return a.profitDensity > b.profitDensity;
}

double greedyKnapsack(vector<Item>& items, int capacity) {
    sort(items.begin(), items.end(), compareItems);
    double totalProfit = 0;
    int currentCapacity = capacity;

    for (int i = 0; i < items.size(); i++) {
        if (items[i].weight <= currentCapacity) {
            totalProfit += items[i].profit;
            currentCapacity -= items[i].weight;
        } else {
            totalProfit += (items[i].profitDensity * currentCapacity);
            break;
        }
    }

    return totalProfit;
}

int main() {
    int n, capacity;
    cout << "Enter the number of items: ";
    cin >> n;
    cout << "Enter the knapsack capacity: ";
    cin >> capacity;

    vector<Item> items(n);
    for (int i = 0; i < n; i++) {
        cout << "Enter weight and profit for item " << i+1 << ": ";
        cin >> items[i].weight >> items[i].profit;
        items[i].profitDensity = (double) items[i].profit / items[i].weight;
    }

    double ratio;
    cout << "Enter the ratio F*(I)/F(I): ";
    cin >> ratio;

    // Measure time
    high_resolution_clock::time_point t1 = high_resolution_clock::now();

    double optimalProfit = greedyKnapsack(items, capacity) / ratio;

    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(t2 - t1).count();

    cout << "Optimal profit using greedy approach: " << optimalProfit << endl;
    cout << "Time taken: " << duration << " microseconds" << endl;

    return 0;
}
