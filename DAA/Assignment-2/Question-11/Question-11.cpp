#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <time.h>
#include <stdlib.h>
#include <sys/time.h>
#define MILLION 1000000

using namespace std;

struct License {
    int index;
    double growthRate;
};

bool compareLicenses(const License& a, const License& b) {
    return a.growthRate > b.growthRate;
}

vector<int> minimizeCostOrder(const vector<double>& growthRates) {
    int n = growthRates.size();
    vector<License> licenses;

    for (int i = 0; i < n; ++i) {
        licenses.push_back({i + 1, growthRates[i]});
    }

    sort(licenses.begin(), licenses.end(), compareLicenses);

    vector<int> order;
    for (const License& license : licenses) {
        order.push_back(license.index);
    }

    return order;
}

int main() {
    srand(time(0)); 

    int n;
    cout << "Enter the number of licenses: ";
    cin >> n;
      
    struct timeval tpstart;
    struct timeval tpend;
    long long timedif;
    srand(time(NULL));
    gettimeofday(&tpstart,NULL);

    // Generate n distinct random growth rates (float values)
    vector<double> growthRates;
    for (int i = 0; i < n; ++i) {
        double rate;
        do {
            rate = (rand() % 100000) / 10000.0 + 1.0; 
        } while (find(growthRates.begin(), growthRates.end(), rate) != growthRates.end());
        growthRates.push_back(rate);
    }

    cout << "Generated Growth Rates: ";
    cout << fixed << setprecision(4);
    for (double rate : growthRates) {
        cout << rate << " ";
    }
    cout << endl;

    vector<int> order = minimizeCostOrder(growthRates);

    cout << "Optimal order to minimize cost:" << endl;
    for (int license : order) {
        cout << license << " ";
    }
    cout << endl;
    
   gettimeofday(&tpend,NULL);
   timedif=MILLION*(tpend.tv_sec-tpstart.tv_sec)+tpend.tv_usec-tpstart.tv_usec;
   fprintf(stderr,"\nIt took %ld microsecond",timedif);

    return 0;
}
