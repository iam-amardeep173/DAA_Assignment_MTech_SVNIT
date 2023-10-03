#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<sys/time.h>
#include<vector>
#include<map>
#include<fstream>

using namespace std;
#define MILLION 1000000

int main()
{
    // Time Analysis
    struct timeval tpstart;
    struct timeval tpend;
    long timediff;

    ifstream VectorInput_Sorted("C:\Users\Amar Deep\OneDrive\Desktop\M Tech\New folder\P22CS017\Assignment 1\Part A\problem 17");
    vector<unsigned long long> vs;
    gettimeofday(&tpstart, NULL);

    if (VectorInput_Sorted.is_open())
    {
        unsigned long long current_number = 0;
        while (VectorInput_Sorted >> current_number)
        {
            vs.push_back(current_number);
        }
    }
    else
    {
        cout << "Couldn't open the file\n";
    }

    long long current, next, difference = 0, new_current = 0, new_next = 0;
    long long min = vs[1] - vs[0];

    if (min < 0)
    {
        min = -min;
    }

    for (long long i = 0; i < vs.size(); i++)
    {
        current = vs[i];
        next = vs[i + 1];

        difference = current - next;

        if (difference < 0)
        {
            difference = -difference;
        }
        if (difference < min)
        {
            min = difference;
            new_current = current;
            new_next = next;
        }
    }
    cout << "Minimum Difference Pair (" << new_current << "," << new_next << ") = " << min << endl;

    gettimeofday(&tpend, NULL);
    timediff = MILLION * (tpend.tv_sec - tpstart.tv_sec) + tpend.tv_usec - tpstart.tv_usec;

    cout << "It took " << timediff << " microseconds" << endl;
    VectorInput_Sorted.close();
    return 0;
}
