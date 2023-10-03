#include <iostream>
#include <climits>
using namespace std;

#define N 20
int heapstate = 0; // 0 = heap, 1 = maxheap, 2 = minheap


void maxheapify(int A[], int heapsize, int i)
{
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int largest = i;

    if (l < heapsize && A[l] > A[largest])
        largest = l;

    if (r < heapsize && A[r] > A[largest])
        largest = r;

    if (largest != i)
    {
        swap(A[i], A[largest]);
        maxheapify(A, heapsize, largest);
    }
}

void minheapify(int A[], int heapsize, int i)
{
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int smallest = i;

    if (l < heapsize && A[l] < A[smallest])
        smallest = l;

    if (r < heapsize && A[r] < A[smallest])
        smallest = r;

    if (smallest != i)
    {
        swap(A[i], A[smallest]);
        minheapify(A, heapsize, smallest);
    }
}

int extract(int A[], int &heapsize)
{
    if (heapsize < 0)
    {
        cout << "Error: Heap is empty ." << endl;
        return INT_MAX;
    }

    // cout << "Extracting........" << endl;
    int tmp = A[0];

    // cout<<"\n temp is \n"<<tmp<<endl;
    A[0] = A[heapsize - 1];
    heapsize = heapsize - 1;

    if (heapstate == 1)
    {
        maxheapify(A, heapsize, 0);
    }
    else if (heapsize == 2)
    {
        minheapify(A, heapsize, 0);
    }
    else if (heapstate == 0)
    {
        // If heapstate is 0, treat it as a binary tree, remove the root element.
        for (int i = 0; i < heapsize; i++)
        {
            A[i] = A[i + 1];
        }
    }
    // cout<<"\n temp is \n"<<tmp<<endl;

    return tmp;
}
void make_min_heap(int A[], int heapsize)
{
    cout << "Making a min heap" << endl;
    for (int i = (heapsize / 2) - 1; i >= 0; i--)
    {
        minheapify(A, heapsize, i);
    }
}

void make_max_heap(int A[], int heapsize)
{
    cout << "Making a max heap" << endl;

    for (int i = (heapsize / 2) - 1; i >= 0; i--)
    {
        maxheapify(A, heapsize, i);
    }
}

void heapsort(int A[], int heapsize)
{
    cout << "Sorting" << endl;

    if (heapstate == 0)
        return;

    if (heapstate == 1)
    {
        for (int i = heapsize - 1; i >= 0; i--)
        {
            swap(A[0], A[i]);
            maxheapify(A, i, 0);
        }
    }
    else
    {
        for (int i = heapsize - 1; i >= 0; i--)
        {
            swap(A[0], A[i]);
            minheapify(A, i, 0);
        }
    }
}
void add(int A[], int &heapsize, int value)
{
    A[heapsize++] = value;

    if (heapstate == 1)
    {
        make_max_heap(A, heapsize);
    }
    if (heapstate == 2)
    {
        make_min_heap(A, heapsize);
    }

    cout << "Added " << value << endl;
}
void print(int A[], int heapsize)
{
    for (int i = 0; i < heapsize; i++)
    {
        cout << A[i] << " - ";
    }
    cout << endl;
}


int main()
{
    int A[N] = {0};
    int heapsize = 0;

    string command;
    int val = 0;
    cout << "add to add, extract to remove,max,min,to sort heap,sort,end to end\n";
    do
    {
        cin >> command;

        if (command == "add")
        {
            cin >> val;
            add(A, heapsize, val);
        }
        else if (command == "extract")
        {
            cout << "Extracted - " << extract(A, heapsize) << endl;
        }
        else if (command == "max")
        {
            heapstate = 1;
            make_max_heap(A, heapsize);
        }
        else if (command == "min")
        {
            heapstate = 2;
            make_min_heap(A, heapsize);
        }
        else if (command == "sort")
        {
            heapsort(A, heapsize);
        }

        print(A, heapsize);

    } while (command != "end");
}
