#include <queue>

void findMedian(int *arr, int n)
{
    if (n == 0)
        return;
    priority_queue<int> MaxHeap;                            // first half
    priority_queue<int, vector<int>, greater<int>> MinHeap; // second half
    MaxHeap.push(arr[0]);
    for (int i = 1; i <= n; i++)
    {
        // print
        if (MinHeap.size() == MaxHeap.size())
        { // if both are equal that means it's EVEN
            cout << (MinHeap.top() + MaxHeap.top()) / 2 << " ";
        }
        else if (abs((int)(MaxHeap.size() - MinHeap.size())) <= 1)
        { // Else ODD
            if (MaxHeap.size() > MinHeap.size())
                cout << MaxHeap.top() << " ";
            else
                cout << MinHeap.top() << " ";
        }

        // insert in correct heap, check where to insert the new element
        if (i < n)
        {
            if (arr[i] < MaxHeap.top())
                MaxHeap.push(arr[i]);
            else
                MinHeap.push(arr[i]);
        }

        // balance out the heap if
        if (MinHeap.size() > MaxHeap.size() + 1)
        {
            MaxHeap.push(MinHeap.top());
            MinHeap.pop();
        }
        if (MaxHeap.size() > MinHeap.size() + 1)
        {
            MinHeap.push(MaxHeap.top());
            MaxHeap.pop();
        }
    }
    cout << endl;
}