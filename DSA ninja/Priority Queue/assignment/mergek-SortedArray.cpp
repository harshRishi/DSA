#include <queue>
#include <vector>

/*Approch*/
/*
- here we've used a min Priority Queue (ie, top element will always be the minimum in the queue)
- so we took every array from the vector and pushed each element into the priority Queue
- after we each every element been pushed we will move top element from pq which is min to the vector
- tham after pq becomes empty return v
*/

vector<int> mergeKSortedArrays(vector<vector<int> *> input)
{
    // Write your code here
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < input.size(); i++)
    {
        for (int j = 0; j < input[i]->size(); j++)
        {
            pq.push(input[i]->at(j));
        }
    }
    vector<int> v;
    while (!pq.empty())
    {
        v.push_back(pq.top());
        pq.pop();
    }
    return v;
}