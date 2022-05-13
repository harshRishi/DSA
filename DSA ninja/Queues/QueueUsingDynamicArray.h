#include <iostream> // Queue using Dynamic array
using namespace std;

template <typename T>
class QueueUsingArray
{
    T *data;
    int nextIndex;
    int firstIndex;
    int size;
    int capacity;

public:
    QueueUsingArray(int s) // parameterised construtor
    {
        data = new T[s];
        nextIndex = 0;
        firstIndex = -1;
        size = 0;
        capacity = s;
    }

    // functions
    int getSize()
    {
        return size;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    void enqueue(T element)
    {
        if (size == capacity)
        {
            T *newData = new T[capacity * 2];
            int j = 0;
            for (int i = firstIndex; i < capacity; i++) // from firstindex  of queue to last
            {
                newData[j++] = data[i];
            }
            for (int i = 0; i < firstIndex; i++) // from 0th index to the firstIndex of the Queue
            {
                newData[j++] = data[i];
            }
            delete[] data;
            data = newData;

            firstIndex = 0;
            nextIndex = capacity;
            capacity *= 2;
        }

        data[nextIndex] = element;
        nextIndex = (nextIndex + 1) % capacity; // this will increase nextIndx in such a way that it become circular in nature

        if (firstIndex == -1)
        {
            firstIndex = 0;
        }
        size++;
    }

    T front()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty!" << endl;
            return 0;
        }
        return data[firstIndex];
    }

    T dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty!" << '\n';
            return 0;
        }
        T ans = data[firstIndex];
        firstIndex = (firstIndex + 1) % capacity;
        size--;
        // reset if size becomes zero
        if (size == 0)
        {
            firstIndex = -1;
            nextIndex = 0;
        }
        return ans;
    }
};