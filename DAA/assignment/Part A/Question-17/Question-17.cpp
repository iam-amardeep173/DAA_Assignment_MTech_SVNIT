#include <iostream>
#include <vector>
#include <climits>

using namespace std;

pair<int, int> findClosestPair(const vector<int>& S) {
    int n = S.size();
    int minDiff = INT_MAX;
    pair<int, int> result;

    for (int i = 1; i < n; ++i) {
        int diff = S[i] - S[i - 1];
        if (diff < minDiff) {
            minDiff = diff;
            result.first = S[i - 1];
            result.second = S[i];
        }
    }

    return result;
}

int main() {
    int n;
    cout << "Enter the number of elements in the sorted array: ";
    cin >> n;

    vector<int> sortedArray(n);
    cout << "Enter the sorted array elements one by one:\n";
    for (int i = 0; i < n; ++i) {
        cin >> sortedArray[i];
    }

    pair<int, int> closestPair = findClosestPair(sortedArray);
    cout << "Closest pair: (" << closestPair.first << ", " << closestPair.second << ")\n";

    return 0;
}
