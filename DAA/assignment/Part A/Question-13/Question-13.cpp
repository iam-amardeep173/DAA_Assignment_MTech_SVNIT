#include <iostream>
#include <vector>
#include <algorithm>
#include<sys/time.h>
using namespace std;

struct Element {
    int key;
    int value;
};

int findValue(const vector<Element>& elements, int x) {
    int left = 0;
    int right = elements.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (elements[mid].key == x) {
            return elements[mid].value;
        } else if (elements[mid].key < x) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}

void insertValue(vector<Element>& elements, int x, int y) {
    Element newElement = {x, y};

    // Find the correct position to insert while maintaining sorted order
    size_t i = 0;
    while (i < elements.size() && elements[i].key < x) {
        ++i;
    }

    // Insert the new element at position i
    elements.insert(elements.begin() + i, newElement);
}

void deleteValue(vector<Element>& elements, int x) {
    // Find the element with the specified key and remove it
    size_t i = 0;
    while (i < elements.size() && elements[i].key != x) {
        ++i;
    }

    // If the element with the key was found, erase it
    if (i < elements.size()) {
        elements.erase(elements.begin() + i);
    }
}

void addValue(vector<Element>& elements, int x, int y) {
    for (Element &el : elements) {
        if (el.key == x) {
            el.value += y;
            break;
        }
    }
}

void addValueToAll(vector<Element>& elements, int y) {
    for (Element &el : elements) {
        el.value += y;
    }
}

int main() {
    vector<Element> elements;
    struct timeval tpstart;
	struct timeval tpend;
	long timedif;

    while (true) {
        cout << "1. Insert(x, y)\n";
        cout << "2. Delete(x)\n";
        cout << "3. Find value(x)\n";
        cout << "4. Add(x, y)\n";
        cout << "5. Add all(y)\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                int x, y;
                cout << "Enter the key (x): ";
                cin >> x;
                cout << "Enter the value (y): ";
                cin >> y;
                gettimeofday(&tpstart, nullptr);
                insertValue(elements, x, y);
                gettimeofday(&tpend, nullptr);
                timedif = 1000000 *(tpend.tv_sec - tpstart.tv_sec) + tpend.tv_usec - tpstart.tv_usec;
	            cout << "Time taken for insert() in microseconds: " << timedif << endl;
                break;
            }
            case 2: {
                int x;
                cout << "Enter the key (x) to delete: ";
                cin >> x;
                gettimeofday(&tpstart, nullptr);
                deleteValue(elements, x);
                gettimeofday(&tpend, nullptr);
                timedif = 1000000 *(tpend.tv_sec - tpstart.tv_sec) + tpend.tv_usec - tpstart.tv_usec;
	            cout << "Time taken for delete() in microseconds: " << timedif << endl;
                break;
            }
            case 3: {
                int x;
                cout << "Enter the key (x): ";
                cin >> x;
                gettimeofday(&tpstart, nullptr);
                int result = findValue(elements, x);
                if (result != -1) {
                    cout << "Value at key " << x << ": " << result << endl;
                } else {
                    cout << "Key " << x << " not found." << endl;
                }
                gettimeofday(&tpend, nullptr);
                timedif = 1000000 *(tpend.tv_sec - tpstart.tv_sec) + tpend.tv_usec - tpstart.tv_usec;
	            cout << "Time taken for findValue() in microseconds: " << timedif << endl;
                break;
            }
            case 4: {
                int x, y;
                cout << "Enter the key (x): ";
                cin >> x;
                cout << "Enter the value to add (y): ";
                cin >> y;
                gettimeofday(&tpstart, nullptr);
                addValue(elements, x, y);
                gettimeofday(&tpend, nullptr);
                timedif = 1000000 *(tpend.tv_sec - tpstart.tv_sec) + tpend.tv_usec - tpstart.tv_usec;
	            cout << "Time taken for addValue() in microseconds: " << timedif << endl;
                break;
            }
            case 5: {
                int y;
                cout << "Enter the value to add to all keys (y): ";
                cin >> y;
                gettimeofday(&tpstart, nullptr);
                addValueToAll(elements, y);
                gettimeofday(&tpend, nullptr);
                timedif = 1000000 *(tpend.tv_sec - tpstart.tv_sec) + tpend.tv_usec - tpstart.tv_usec;
	            cout << "Time taken for addValueToAll() in microseconds: " << timedif << endl;
                break;
            }
            case 6:
                cout << "Exiting the program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
                break;
        }
    }

    return 0;
}