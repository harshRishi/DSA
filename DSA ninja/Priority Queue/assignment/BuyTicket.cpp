#include <queue>

/*Approch*/
/*
- take Queue and Priority Queue to store indexs of the element and there priority
- make your priority Q with arr;
- make a time int variable
- make a while untill our Priority_queue ends
- now If our arr[queue'th element] is equal to pq.top that means it's time to give ticket to the person
- now if that prior person is having same index as that we the person we're looking for (ie. k) then simply return time with 1+
- if not than simply have over the ticket to the perior person and pop it out of the PQ and so as remove it's index from the queue also
- if arr[queue'th element] is not equal simply move the queue ahead <move  front to end>
*/
int buyTicket(int *arr, int n, int k)
{
    // Write your code here
    queue<int> q;           // this will store index of each element
    priority_queue<int> pq; // this will store the priority of the elements

    for (int i = 0; i < n; i++)
    {
        q.push(i);
        pq.push(arr[i]);
    }

    int time = 0;
    while (!pq.empty())
    {
        if (arr[q.front()] == pq.top())
        {
            if (q.front() == k)
                return ++time;

            pq.pop(); // most prior element popped
            time++;
            q.pop(); // front popped
            continue;
        }
        // move our queue ahead and put the front index to the back
        int front = q.front();
        q.pop();
        q.push(front);
    }
}