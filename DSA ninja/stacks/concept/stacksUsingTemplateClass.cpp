#include <iostream> // stacks usng templates
#include <climits>
using namespace std;

template <typename T>

class StackUsingArray
{
    int nextIndex; // private property
    T *data;
    int capacity;

public:
    StackUsingArray()
    {
        nextIndex = 0;
        capacity = 4;
        data = new T[capacity];
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
    void push(T element)
    {
        if (nextIndex == capacity)
        {
            // cout << "Stack full" << endl;
            // return;

            T *newData = new T[2 * capacity]; // here we've used dynamic arrays to solve the size problem
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
    T pop()
    {
        if (isEmpty())
        {
            cout << "Empty Stack" << endl;
            // return INT_MIN; we can not return INT_MIN as the return type is T not int
            return 0;
        }
        return data[--nextIndex];
    }

    // reading the top element
    T top()
    {
        if (isEmpty())
        {
            cout << "Empty Stack" << endl;
            return 0;
        }
        return data[nextIndex - 1];
    }
};