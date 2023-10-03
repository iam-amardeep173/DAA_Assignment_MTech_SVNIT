// Program 1 --- some sorting
// compile: g++ program1.cpp
// usage: a.out 100
// (replace "100" by the array size you want)
//
// Name:
//
// Date submitted:
//

#include<stdlib.h>
#include<iostream>
#include<time.h>
#include<sys/time.h>
#include<vector>
#include<map>
#include<fstream>

using namespace std;
#define MILLION 1000000

// Declarations
void bubbleSort(int a[]);
void insertSort(int a[]);
void merge(int a[], int left, int middle, int right);
void mergeSort(int a[], int left, int right);
void merge_mySorts(int a[], int left, int middle, int right);
void mySort(int a[], int left, int right);
void semiBubbleSort(int a[]);
void fillRandom(int a[]);
void check(int a[]);

int N = 0;                      // Global for array size

int main(int argc, char *argv[])
{
    timeval t;                  // for timing the sorts
    int starttime, endtime;     // for timing the sorts
    N = atoi(argv[1]);          // set size of array
    int a[N];

    // time a bubble sort
    fillRandom(a);
    gettimeofday(&t, NULL);
    starttime = t.tv_sec;
    bubbleSort(a);
    gettimeofday(&t, NULL);
    endtime = t.tv_sec;
    cout << "Bubble Sort time = " << endtime - starttime << endl;
    check(a);

    // time an insertion sort
    fillRandom(a);
    gettimeofday(&t, NULL);
    starttime = t.tv_sec;
    insertSort(a);
    gettimeofday(&t, NULL);
    endtime = t.tv_sec;
    cout << "Insertion Sort time = " << endtime - starttime << endl;
    check(a);

    // time a merge sort
    fillRandom(a);
    gettimeofday(&t, NULL);
    starttime = t.tv_sec;
    mergeSort(a, 0, N - 1);
    gettimeofday(&t, NULL);
    endtime = t.tv_sec;
    cout << "Merge Sort time = " << endtime - starttime << endl;
    check(a);

    // time a "my" sort
    fillRandom(a);
    gettimeofday(&t, NULL);
    starttime = t.tv_sec;
    mySort(a, 0, N - 1);
    gettimeofday(&t, NULL);
    endtime = t.tv_sec;
    cout << "My Sort time = " << endtime - starttime << endl;
    check(a);

    // time a semi-bubble sort
    fillRandom(a);
    gettimeofday(&t, NULL);
    starttime = t.tv_sec;
    semiBubbleSort(a);
    gettimeofday(&t, NULL);
    endtime = t.tv_sec;
    cout << "Semi-Bubble Sort time = " << endtime - starttime << endl;
    check(a);

    return 0;
}

void bubbleSort(int a[])
{
    for(int i = 0; i <= N; i++)
        for(int j = 0; j < N-1; j++)
            if(a[j] > a[j+1])
            {
                int tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
            }
    return;
}

void insertSort(int a[])
{
    for (int i = 1; i < N; i++)
    {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }

    return;
}

void merge(int a[], int left, int middle, int right)
{
    int n1 = middle - left + 1;
    int n2 = right - middle;
    int leftArr[n1];
    int rightArr[n2];

    for (int i = 0; i < n1; i++)
    {
        leftArr[i] = a[left + i];
    }

    for (int i = 0; i < n2; i++)
    {
        rightArr[i] = a[middle + 1 + i];
    }

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2)
    {
        if (leftArr[i] <= rightArr[j])
        {
            a[k++] = leftArr[i++];
        }
        else
        {
            a[k++] = rightArr[j++];
        }
    }

    while (i < n1)
    {
        a[k++] = leftArr[i++];
    }

    while (j < n2)
    {
        a[k++] = rightArr[j++];
    }
}

void mergeSort(int a[], int left, int right)
{
    if (left < right)
    {
        int middle = left + (right - left) / 2;
        mergeSort(a, left, middle);
        mergeSort(a, middle + 1, right);
        merge(a, left, middle, right);
    }
}

void merge_mySort(int a[], int left, int middle, int right)
{
    int i = left, j = middle + 1, k = 0;
    int* temp = (int*)calloc(right - left + 1, sizeof(int));

    while ((i <= middle) && (j <= right))
        if (a[i] < a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    while (j <= right)
        temp[k++] = a[j++];
    while (i <= middle)
        temp[k++] = a[i++];

    for (i = left, k = 0; i <= right; i++, k++)
        a[i] = temp[k];
    free(temp);
}

void mySort(int a[], int left, int right)
{
    if (left < right)
    {
        int middle = left + (right - left) / 2;
        mergeSort(a, left, middle);
        mergeSort(a, middle + 1, right);

        if (a[middle] > a[middle + 1])
        {
            merge_mySort(a, left, middle, right);
        }
    }
}

void semiBubbleSort(int a[])
{
    bool flag;
    for(int i = 0; i <= N; i++)
    {
        flag = false;
        for(int j = 0; j < N-1; j++)
        {
            if(a[j] > a[j+1])
            {
                int tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
                flag = true;
            }
        }

        if (!flag)
            break;
    }
    return;
}

void fillRandom(int a[])
{
    for(int i = 0; i < N; i++)
        a[i] = rand();
    return;
}

void check(int a[])
{
    for(int i = 0; i < N-1; i++)
        if(a[i] > a[i+1])
        {
            cout << "Failed to sort. See item " << i << endl << endl;
            return;
        }
    cout << "Check passed" << endl << endl;
}
