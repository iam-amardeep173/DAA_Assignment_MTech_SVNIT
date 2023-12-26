#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>
#include <ctime>

using namespace std;

// Define a structure to represent a stick
struct Stick {
    int x1, y1, z1;  // First endpoint coordinates
    int x2, y2, z2;  // Second endpoint coordinates
    bool isPicked;   // To track if the stick has been picked up
};

// Function to compare two sticks a and b and determine their relationship
string compareSticks(const Stick& a, const Stick& b) {
    // Check if a is above b
    if ((a.x1 >= b.x1 && a.x2 <= b.x2) &&
        (a.y1 >= b.y1 && a.y2 <= b.y2) &&
        (a.z1 >= b.z1 && a.z2 <= b.z2)) {
        return "Above";
    }
    // Check if a is below b
    if ((b.x1 >= a.x1 && b.x2 <= a.x2) &&
        (b.y1 >= a.y1 && b.y2 <= a.y2) &&
        (b.z1 >= a.z1 && b.z2 <= a.z2)) {
        return "Below";
    }
    return "Unrelated";
}

// Function to pick up a stick and mark it as picked
void pickStick(Stick& stick) {
    stick.isPicked = true;
}

// Function to check if all sticks can be picked up and provide a sequence
bool canPickAllSticks(vector<Stick>& sticks, vector<Stick>& sequence) {
    sequence.clear();  // Clear the sequence
    int remainingSticks = sticks.size();

    while (remainingSticks > 0) {
        bool picked = false;

        for (int i = 0; i < sticks.size(); i++) {
            if (!sticks[i].isPicked) {
                bool canPick = true;

                for (int j = 0; j < sticks.size(); j++) {
                    if (i != j && !sticks[j].isPicked) {
                        string relation = compareSticks(sticks[i], sticks[j]);
                        if (relation == "Above") {
                            canPick = false;
                            break;
                        }
                    }
                }

                if (canPick) {
                    pickStick(sticks[i]);
                    sequence.push_back(sticks[i]);
                    remainingSticks--;
                    picked = true;
                }
            }
        }

        if (!picked) {
            // If no stick was picked in this iteration, it's impossible to pick up all sticks
            return false;
        }
    }

    return true;
}

int main() {
    // Seed the random number generator
    srand(static_cast<unsigned>(time(0)));

    // Generate a random set of sticks
    int N = 10; // Number of sticks

    
    vector<Stick> sticks;
    for (int i = 0; i < N; i++) {
        Stick stick;
        stick.x1 = rand() % 10;
        stick.y1 = rand() % 10;
        stick.z1 = rand() % 10;
        stick.x2 = rand() % 10;
        stick.y2 = rand() % 10;
        stick.z2 = rand() % 10;
        stick.isPicked = false;
        sticks.push_back(stick);
    }

    // Measure the time duration
    auto start_time = chrono::high_resolution_clock::now();

    vector<Stick> sequence;
    if (canPickAllSticks(sticks, sequence)) {
        cout << "It is possible to pick up all sticks in the following sequence:\n";
        for (const Stick& stick : sequence) {
            cout << "Pick up stick (" << stick.x1 << ", " << stick.y1 << ", " << stick.z1 << ") to ("
                 << stick.x2 << ", " << stick.y2 << ", " << stick.z2 << ")\n";
        }
    } else {
        cout << "It is impossible to pick up all sticks.\n";
    }

    // Measure the time duration
    auto end_time = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end_time - start_time);

    cout << "Time taken by function: " << duration.count() << " microseconds" << endl;

    return 0;
}