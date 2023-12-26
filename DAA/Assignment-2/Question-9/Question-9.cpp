#include <iostream>
#include <vector>

struct PetrolStation {
    int distance;  // Distance from the starting point
    int petrol;    // Amount of petrol available at the station

    PetrolStation(int d, int p) : distance(d), petrol(p) {}
};

std::vector<int> findOptimalPetrolStations(const std::vector<PetrolStation>& stations, int n, int maxTankCapacity) {
    std::vector<int> optimalStops;  // List of indices for optimal petrol stations to stop

    int currentPos = 0;            // Current position of the car
    int currentTank = maxTankCapacity;

    for (int i = 0; i < n; i++) {
        int distanceToNextStation = stations[i].distance - currentPos;

        // If we can reach the next station with current fuel
        if (distanceToNextStation <= currentTank) {
            currentTank -= distanceToNextStation;
        } else {
            // Need to make a stop at the nearest petrol station
            if (currentPos != stations[i].distance) {
                optimalStops.push_back(i - 1);
                currentTank = maxTankCapacity;
            } else {
                // The nearest station is at the current location, so we need to backtrack
                return {};
            }
        }

        currentPos = stations[i].distance;
    }

    return optimalStops;
}

int main() {
    int n;  // Number of petrol stations
    int maxTankCapacity;  // Maximum tank capacity of the car
    std::cout << "Enter the number of petrol stations: ";
    std::cin >> n;

    std::vector<PetrolStation> stations;

    std::cout << "Enter the distance and petrol available at each station:\n";
    for (int i = 0; i < n; i++) {
        int distance, petrol;
        std::cin >> distance >> petrol;
        stations.push_back(PetrolStation(distance, petrol));
    }

    std::cout << "Enter the maximum tank capacity of the car: ";
    std::cin >> maxTankCapacity;

    std::vector<int> optimalStops = findOptimalPetrolStations(stations, n, maxTankCapacity);

    if (optimalStops.empty()) {
        std::cout << "It's not possible to reach New Delhi with the given data.";
    } else {
        std::cout << "Optimal petrol stations to stop at: ";
        for (int index : optimalStops) {
            std::cout << stations[index].distance << " ";
        }
    }

    return 0;
}
