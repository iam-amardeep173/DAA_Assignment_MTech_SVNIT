#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Structure to represent a job with start and end times
struct Job {
    int start;
    int end;
};

// Function to compare jobs based on their end times
bool compareJobs(const Job& a, const Job& b) {
    return a.end < b.end;
}

// Merge function for merge sort
void merge(vector<Job>& jobs, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<Job> leftSubarray(n1);
    vector<Job> rightSubarray(n2);

    for (int i = 0; i < n1; i++) {
        leftSubarray[i] = jobs[left + i];
    }

    for (int i = 0; i < n2; i++) {
        rightSubarray[i] = jobs[mid + 1 + i];
    }

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (leftSubarray[i].end <= rightSubarray[j].end) {
            jobs[k] = leftSubarray[i];
            i++;
        } else {
            jobs[k] = rightSubarray[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        jobs[k] = leftSubarray[i];
        i++;
        k++;
    }

    while (j < n2) {
        jobs[k] = rightSubarray[j];
        j++;
        k++;
    }
}

// Merge sort function
void mergeSort(vector<Job>& jobs, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(jobs, left, mid);
        mergeSort(jobs, mid + 1, right);
        merge(jobs, left, mid, right);
    }
}

void generateRandomJobs(vector<Job>& jobs, int n) {
    for (int i = 0; i < n; i++) {
        Job job;
        job.start = rand() % 24;   // Random start time between 0 and 23
        job.end = job.start + 1 + rand() % (24 - job.start);  // Random end time (start + 1 to 24)
        jobs.push_back(job);
    }
}

void scheduleJobs(vector<Job>& jobs) {
    int n = jobs.size();

    // Sort the jobs by their end times using merge sort
    mergeSort(jobs, 0, n - 1);

    vector<Job> selectedJobs;
    selectedJobs.push_back(jobs[0]);
    int lastEndTime = jobs[0].end;

    for (int i = 1; i < n; i++) {
        if (jobs[i].start >= lastEndTime) {
            // Select the job if it doesn't overlap with the previous one
            selectedJobs.push_back(jobs[i]);
            lastEndTime = jobs[i].end;
        }
    }

    // Print the selected jobs
    cout << "Selected jobs: " << endl;
    for (const Job& job : selectedJobs) {
        cout << "Start: " << job.start << " End: " << job.end << endl;
    }
}

int main() {
    srand(static_cast<unsigned>(time(nullptr)));  // Seed the random number generator

    int numJobs = 50;  // Change this to the desired number of random jobs
    vector<Job> jobs;

    // Measure time duration for generating random jobs
    auto start_time = high_resolution_clock::now();
    generateRandomJobs(jobs, numJobs);
    auto end_time = high_resolution_clock::now();
    auto generate_jobs_duration = duration_cast<microseconds>(end_time - start_time).count();

    // Measure time duration for scheduling jobs
    start_time = high_resolution_clock::now();
    scheduleJobs(jobs);
    end_time = high_resolution_clock::now();
    auto schedule_jobs_duration = duration_cast<microseconds>(end_time - start_time).count();

    cout << "Time duration for generating random jobs: " << generate_jobs_duration << " microseconds" << endl;
    cout << "Time duration for scheduling jobs: " << schedule_jobs_duration << " microseconds" << endl;

    return 0;
}
