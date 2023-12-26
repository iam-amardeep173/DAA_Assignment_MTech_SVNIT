#include <iostream>
#include <vector>
#include <ctime>

using namespace std;
vector<pair<int, int>> intervals;
int N;

int sortOnStart()
{
    N = intervals.size();

    for (int i = 1; i < N; i++)
    {
        int j = i - 1;
        int temp1 = intervals.at(i).first;
        int temp2 = intervals.at(i).second;
        while (j >= 0 && intervals.at(j).first < temp1)
        {
            intervals.at(j + 1).first = intervals.at(j).first;
            intervals.at(j + 1).second = intervals.at(j).second;
            j--;
        }
        intervals.at(j + 1).first = temp1;
        intervals.at(j + 1).second = temp2;
    }

    int count_act = 1;
    int begin = intervals.at(0).first;
    for (int i = 1; i < N; i++)
    {
        if (intervals.at(i).second <= begin)
        {
            count_act++;
            begin = intervals.at(i).first;
        }
    }

    return count_act;
}

int optimalSort()
{
    N = intervals.size();

    for (int i = 1; i < N; i++)
    {
        int j = i - 1;
        int temp1 = intervals.at(i).first;
        int temp2 = intervals.at(i).second;
        while (j >= 0 && intervals.at(j).second > temp2)
        {
            intervals.at(j + 1).first = intervals.at(j).first;
            intervals.at(j + 1).second = intervals.at(j).second;
            j--;
        }
        intervals.at(j + 1).first = temp1;
        intervals.at(j + 1).second = temp2;
    }

    int count_act = 1;
    int begin = intervals.at(0).second;
    for (int i = 1; i < N; i++)
    {
        if (intervals.at(i).first >= begin)
        {
            count_act++;
            begin = intervals.at(i).second;
        }
    }

    return count_act;
}

int main()
{
    cout << "Enter the intervals (-1) to stop\n";

    while (1)
    {
        int start, end;
        cin >> start;
        if (start == -1)
            break;
        cin >> end;
        if (end == -1)
            break;
        pair<int, int> interval;
        interval.first = start;
        interval.second = end;
        intervals.push_back(interval);
    }

    struct timespec tpstart, tpend;

    clock_gettime(CLOCK_MONOTONIC, &tpstart);
    int count1 = sortOnStart();
    clock_gettime(CLOCK_MONOTONIC, &tpend);

    long long time_diff = (tpend.tv_sec - tpstart.tv_sec) * 1000000000 + (tpend.tv_nsec - tpstart.tv_nsec);
    cout << "Activities selected in lastStart first : " << count1 << endl;
    cout << "Time required in lastStart first: " << time_diff << " nanoseconds" << endl;

    clock_gettime(CLOCK_MONOTONIC, &tpstart);
    int count2 = optimalSort();
    clock_gettime(CLOCK_MONOTONIC, &tpend);

    time_diff = (tpend.tv_sec - tpstart.tv_sec) * 1000000000 + (tpend.tv_nsec - tpstart.tv_nsec);
    cout << "Activities selected in optimal algo  : " << count2 << endl;
    cout << "Time required in optimal algo : " << time_diff << " nanoseconds" << endl;
}
