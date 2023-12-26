#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <chrono>

using namespace std;
using namespace chrono;

// Function to check if a given string is a valid word
bool dict(const string& word, const unordered_set<string>& dictionary) {
    return dictionary.count(word) > 0;
}

// Dynamic programming algorithm to reconstruct the document
bool canReconstruct(const string& s, const unordered_set<string>& dictionary) {
    int n = s.length();

    // dp[i] represents whether the substring s[0...i-1] can be reconstructed using the dictionary
    vector<bool> dp(n + 1, false);
    dp[0] = true;

    for (int i = 1; i <= n; ++i) {
        for (int j = i - 1; j >= 0; --j) {
            string word = s.substr(j, i - j);
            if (dp[j] && dict(word, dictionary)) {
                dp[i] = true;
                break;
            }
        }
    }

    return dp[n];
}

// Function to output the reconstructed sequence of words
void outputWords(const string& s, const unordered_set<string>& dictionary) {
    int n = s.length();

    // dp[i] represents whether the substring s[0...i-1] can be reconstructed using the dictionary
    vector<bool> dp(n + 1, false);
    dp[0] = true;

    // parent[i] stores the index of the last word ending at position i
    vector<int> parent(n + 1, -1);

    for (int i = 1; i <= n; ++i) {
        for (int j = i - 1; j >= 0; --j) {
            string word = s.substr(j, i - j);
            if (dp[j] && dict(word, dictionary)) {
                dp[i] = true;
                parent[i] = j;
                break;
            }
        }
    }

    // Reconstruct the sequence of words
    int idx = n;
    while (idx > 0) {
        int prev = parent[idx];
        cout << s.substr(prev, idx - prev) << " ";
        idx = prev;
    }
    cout << endl;
}

int main() {
    // Input the text
    cout << "Enter the text: ";  //itwasthebestoftime
    string s;
    getline(cin, s);

    // Input the dictionary
    cout << "Enter the number of words in the dictionary: ";//6
    int numWords;
    cin >> numWords;

    unordered_set<string> dictionary;
    cout << "Enter the words in the dictionary, one per line:" << endl;
    for (int i = 0; i < numWords; ++i) {
        string word;
        cin >> word;
        dictionary.insert(word);
    }

    // Measure the time taken by the algorithm
    auto start = high_resolution_clock::now();

    // Check if the string can be reconstructed
    if (canReconstruct(s, dictionary)) {
        cout << "The string can be reconstructed." << endl;
        cout << "Reconstructed sequence of words: ";
        outputWords(s, dictionary);
    } else {
        cout << "The string cannot be reconstructed." << endl;
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Time taken by the algorithm: " << duration.count() << " microseconds" << endl;

    return 0;
}
