#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

// Structure to represent a person and their rumors
struct Person {
    int id;
    vector<int> rumors;

    Person(int id) : id(id) {
        rumors.clear();
    }
};

// Custom comparator for sorting people based on the number of rumors
bool comparePeople(const Person& a, const Person& b) {
    return a.rumors.size() > b.rumors.size();
}

int main() {
    int n; // Number of people
    int m; // Number of rumors

    cout << "Enter the number of people: ";
    cin >> n;
    cout << "Enter the number of rumors: ";
    cin >> m;

    vector<Person> people;

    // Initialize people with IDs and no rumors
    for (int i = 0; i < n; i++) {
        people.push_back(Person(i));
    }

    // Input rumors for each person
    for (int i = 0; i < m; i++) {
        int numRumors;
        cout << "Enter the number of rumors for person " << i << ": ";
        cin >> numRumors;
        cout << "Enter the rumor IDs (space-separated) for person " << i << ": ";
        for (int j = 0; j < numRumors; j++) {
            int rumor;
            cin >> rumor;
            people[i].rumors.push_back(rumor);
        }
    }

    // Sort people in descending order of the number of rumors
    sort(people.begin(), people.end(), comparePeople);

    // Create a list of people who need rumors
    list<Person> peopleNeedingRumors(people.begin(), people.end());

    int messagesSent = 0;

    while (!peopleNeedingRumors.empty()) {
        Person sender = peopleNeedingRumors.front();
        peopleNeedingRumors.pop_front();

        // Share rumors with people who need them
        for (auto it = peopleNeedingRumors.begin(); it != peopleNeedingRumors.end();) {
            for (int rumor : sender.rumors) {
                if (find(it->rumors.begin(), it->rumors.end(), rumor) != it->rumors.end()) {
                    it->rumors.erase(remove(it->rumors.begin(), it->rumors.end(), rumor), it->rumors.end());
                }
            }

            if (it->rumors.empty()) {
                it = peopleNeedingRumors.erase(it);
            } else {
                ++it;
            }
        }

        messagesSent++;
    }

    cout << "Minimum number of messages needed: " << messagesSent << endl;

    return 0;
}
