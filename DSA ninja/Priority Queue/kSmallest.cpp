#include <queue>
vector<int> kSmallest(int arr[], int n, int k)
{
    // Write your code here
    priority_queue<int> p;
    for (int i = 0; i < k; i++) // consider first k elements to be smallest and as they're in the max PQ so at the top there will be max of all k in the pQ
    {
        p.push(arr[i]);
    }

    for (int i = k; i < n; i++) // compare the largest element with all element after k -1 index ie. kth index
    {
        int max = p.top();
        if (arr[i] < max) // comparing
        {
            p.push(arr[i]);
            p.pop();
        }
    }
    // By this time oour PriorityQueue will be having k smallest element from the array
    vector<int> v;
    while (!p.empty())
    {
        v.push_back(p.top()); // insert element one by one from the P-queue to the vector v
        p.pop();
    }
    return v;
}