#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class MinHeapSet
{
private:
    vector<int> heap;

    // Helper function to maintain the heap property
    void heapifyUp(int index);
    void heapifyDown(int index);

public:
    // Insert an element into the set
    void insert(int x);

    // Delete the kth smallest element from the set
    void deleteKthSmallest(int k);

    // Check if an element is a member of the set
    bool member(int x) const;

    // Get the size of the set
    size_t size() const { return heap.size(); }
};

// Helper function to maintain the heap property while inserting
void MinHeapSet::heapifyUp(int index)
{
    while (index > 0)
    {
        int parentIndex = (index - 1) / 2;
        if (heap[index] < heap[parentIndex])
        {
            swap(heap[index], heap[parentIndex]);
            index = parentIndex;
        }
        else
        {
            break;
        }
    }
}

// Helper function to maintain the heap property while deleting
void MinHeapSet::heapifyDown(int index)
{
    while (true)
    {
        int leftChildIndex = 2 * index + 1;
        int rightChildIndex = 2 * index + 2;
        int smallestIndex = index;

        if (leftChildIndex < heap.size() && heap[leftChildIndex] < heap[smallestIndex])
        {
            smallestIndex = leftChildIndex;
        }

        if (rightChildIndex < heap.size() && heap[rightChildIndex] < heap[smallestIndex])
        {
            smallestIndex = rightChildIndex;
        }

        if (smallestIndex != index)
        {
            swap(heap[index], heap[smallestIndex]);
            index = smallestIndex;
        }
        else
        {
            break;
        }
    }
}

// Insert an element into the set
void MinHeapSet::insert(int x)
{
    heap.push_back(x);
    heapifyUp(heap.size() - 1);
}

// Delete the kth smallest element from the set
void MinHeapSet::deleteKthSmallest(int k)
{
    if (k < 1 || k > heap.size())
    {
        cout << "Invalid k value for delete operation" << endl;
        return;
    }

    swap(heap[k - 1], heap[heap.size() - 1]);
    heap.pop_back();
    heapifyDown(k - 1);
}

// Check if an element is a member of the set
bool MinHeapSet::member(int x) const
{
    return find(heap.begin(), heap.end(), x) != heap.end();
}

int main()
{
    MinHeapSet minHeapSet;

    // Insertion
    cout<<"inserting 10,21,5,30,25"<<endl;
    minHeapSet.insert(10);
    minHeapSet.insert(21);
    minHeapSet.insert(5);
    minHeapSet.insert(35);
    minHeapSet.insert(25);

    // Deletion
    cout << "removing 2" << endl;
    minHeapSet.deleteKthSmallest(2); // Delete the 2nd smallest element (10)

    // Membership test
    cout << "1 for yes, 0 for no" << endl;
    cout << "Is 10 a member? " << minHeapSet.member(10) << endl; // Should print 0 (false)
    cout << "Is 2 a member? " << minHeapSet.member(2) << endl;   // Should print 1 (true)

    return 0;
}
