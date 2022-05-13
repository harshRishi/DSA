#include <iostream>
#include <queue>
using namespace std;

void kSort(int input[], int n, int k)
{
    priority_queue<int> p;
    for (int i = 0; i < k; i++) // in PQ element will automatically heap them self to make root as max element as inbuilt pq is max in nature
    {
        p.push(input[i]);
    }

    int j = 0; // this will note where to place the max element in the original array i.e input
    for (int i = k; i < n; i++)
    {
        input[j++] = p.top(); // palced the max out of k elements from the priorityOueue
        p.pop();              // removed the max element from the PQ
        p.push(input[i]);     // pushed next element in the PQ  after k-1 element (i.e kth element)
    }                         // by this course of action we have sorted n-k elements

    while (!p.empty()) // this will fill rest of the k elements from the PQ to the array
    {
        input[j++] = p.top();
        p.pop();
    }
}

int main()
{
    int input[] = {10, 12, 6, 7, 8};
    int k = 3;
    kSort(input, 5, k);

    for (int i = 0; i < 5; i++)
    {
        cout << input[i] << " ";
    }
}