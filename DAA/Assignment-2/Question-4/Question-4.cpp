#include <iostream>
#include <vector>
#include <algorithm>
#include<chrono>

struct Activity {
    int start;
    int end;
    int index;

    bool operator<(const Activity& other) const {
        return end < other.end;
    }
};

void insertionSort(std::vector<Activity>& activities) {
    int n = activities.size();
    for (int i = 1; i < n; ++i) {
        Activity key = activities[i];
        int j = i - 1;

        // Compare based on the end times
        while (j >= 0 && activities[j].end > key.end) {
            activities[j + 1] = activities[j];
            j--;
        }

        activities[j + 1] = key;
    }
}


int scheduleLectureHalls(std::vector<Activity>& activities) {
    insertionSort(activities); // Add a semicolon here

    std::vector<int> lectureHalls; // Stores the end time of the activities in each lecture hall
    lectureHalls.push_back(activities[0].end);

    for (int i = 1; i < activities.size(); i++) {
        bool scheduled = false;

        for (int j = 0; j < lectureHalls.size(); j++) {
            if (activities[i].start >= lectureHalls[j]) {
                lectureHalls[j] = activities[i].end;
                scheduled = true;
                break;
            }
        }

        if (!scheduled) {
            lectureHalls.push_back(activities[i].end);
        }
    }

    return lectureHalls.size();
}

int main() {
    std::vector<Activity> activities = {
        {0, 1, 1},
        {1, 2, 2},
        {1, 3, 3},
        {2, 4, 4},
        {3, 5, 5}
    };
     auto start = std::chrono::high_resolution_clock::now();
    int minHalls = scheduleLectureHalls(activities);
     auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << "Minimum number of lecture halls needed: " << minHalls << std::endl;
    std::cout << "Execution time: " << duration.count() << " microseconds" << std::endl;


    return 0;
}
