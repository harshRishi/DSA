#include <iostream>
#include <climits>
using namespace std;

class StackUsingArray
{
    int nextIndex; // private property
    int *data;
    int capacity;

public:
    StackUsingArray()
    {
        nextIndex = 0;
        capacity = 4;
        data = new int[capacity];
    }

    // function : Size of stack
    int size()
    {
        return nextIndex;
    }

    // function : checking if stack is empty or not
    bool isEmpty()
    {
        // nextIndex == 0 ? return true : return false;

        return nextIndex == 0;
    }

    // Insert Element In the Stack
    void push(int element)
    {
        if (nextIndex == capacity)
        {
            // cout << "Stack full" << endl;
            // return;

            int *newData = new int[2 * capacity]; // here we've used dynamic arrays to solve the size problem
            for (int i = 0; i < capacity; i++)
            {
                newData[i] = data[i];
            }
            capacity *= 2; // increase the capacity twice

            delete[] data;
            data = newData;
        }
        data[nextIndex++] = element;
    }

    // deleting element from the stack
    int pop()
    {
        if (isEmpty())
        {
            cout << "Empty Stack" << endl;
            return INT_MIN;
        }
        return data[--nextIndex];
    }

    // reading the top element
    int top()
    {
        if (isEmpty())
        {
            cout << "Empty Stack" << endl;
            return INT_MIN;
        }
        return data[nextIndex - 1];
    }
};