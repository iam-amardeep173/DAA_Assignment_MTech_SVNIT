#include <iostream>
#include <vector>
#include <unordered_set>
#include <random>
#include <chrono>
#include <fstream>
using namespace std;

vector<int> generateDataset(int size) {
    vector<int> dataset;
    random_device rd;
    mt19937 rng(rd());

    for (int i = 0; i < size; i++) {
        int randValue = uniform_int_distribution<int>(1, INT_MAX)(rng);
        dataset.push_back(randValue);
    }

    return dataset;
}

int findFreeIntegralValue(int value, unordered_set<int>& seen) {
    int newValue = value;
    while (seen.count(newValue) > 0) {
        newValue++;
    }
    return newValue;
}

int removeDuplicates(vector<int>& dataset) {
    unordered_set<int> seenData;
    int duplicatesRemoved = 0;

    for (int i = 0; i < dataset.size(); i++) {
        int current = dataset[i];

        if (seenData.count(current) > 0) {
            int newValue = findFreeIntegralValue(current, seenData);
            dataset[i] = newValue;
            duplicatesRemoved++;
        }
        seenData.insert(dataset[i]);
    }

    return duplicatesRemoved;
}

int main() {
    vector<int> dataset = generateDataset(1000000);
    auto startTime = chrono::high_resolution_clock::now();
    int duplicatesRemoved = removeDuplicates(dataset);
    auto endTime = chrono::high_resolution_clock::now();
    chrono::microseconds duration = chrono::duration_cast<chrono::microseconds>(endTime - startTime);

    cout << "Time taken to remove duplicates: " << duration.count() << " microseconds" << endl;
    cout << "Number of duplicates removed: " << duplicatesRemoved << endl;
    return 0;
}
