#include <iostream>
#include <queue>
using namespace std;

// APPROCH:
// here also same as stack we've used recursion as a temporary stack so that we can reverse the queue except the first element which we will push to the reversed queue

void reverseQueue(queue<int> &input)
{
    // Write your code here
    // Base Case
    if (input.size() == 0 || input.empty()) // here if ther is no element or one element in the queue than it is already reversed. so simply return
    {
        return;
    }

    int temp = input.front();
    input.pop();

    reverseQueue(input); // After popping the first element

    input.push(temp);
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        queue<int> q;
        int size;
        cin >> size;

        for (int i = 0, val; i < size; i++)
        {
            cin >> val;
            q.push(val);
        }

        reverseQueue(q);
        while (!q.empty())
        {
            cout << q.front() << " ";
            q.pop();
        }

        cout << "\n";
    }
}