#include <vector>
#include <queue>

vector<int> kLargest(int input[], int n, int k)
{
    priority_queue<int, vector<int>, greater<int>> p; // Used default Min priority Queue
    for (int i = 0; i < k; i++)
    {
        p.push(input[i]);
    }

    for (int i = k; i < n; i++)
    {
        int min = p.top();
        if (input[i] > min)
        {
            p.push(input[i]);
            p.pop();
        }
    }

    vector<int> v;
    while (!p.empty())
    {
        v.push_back(p.top());
        p.pop();
    }

    return v;
}