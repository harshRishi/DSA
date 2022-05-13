#include <queue>
#include <vector>

/*Approch*/
/*
---- see Klargest and kSmallest -------
- same as that of finding k largest element from the array accept here we need to find the largest kth element
- so out of the min Priority Queue we only need the top most element which is k th largest element of the array
*/
int kthLargest(int *arr, int n, int k)
{
    // convert the arr into a heap
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < k; i++)
    { // considering first k elements to be k largest element from the array
        pq.push(arr[i]);
    }

    // here we're using min heap or Min priorityQUEUE
    for (int i = k; i < n; i++)
    { // if we found any element greater than min element from our PQ than replace it with our new element
        if (arr[i] > pq.top())
        {
            pq.push(arr[i]); // pushed the new element
            pq.pop();        // and after a push we kicked out the min element to maintain k element in the pq
        }
    }

    return pq.top(); // as this is a Min priorityQUeue so at the top there will be miniMum of k-largest element of the array
}