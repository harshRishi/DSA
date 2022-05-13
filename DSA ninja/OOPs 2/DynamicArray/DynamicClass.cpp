#include <iostream>
using namespace std;

class DynamicArray
{
    int *data;
    int nextIndex, capacity;

public:
    DynamicArray()
    {
        data = new int[5];
        nextIndex = 0; 
        capacity = 5;
    }

    DynamicArray(DynamicArray const &d) // making our very own copy consturtor.
    {
        // this->data = d.data; // this is default shallow copy by copy construtor and copy asignment operator
        // making a deep copy.
        this->data = new int[d.capacity];
        for (int i = 0; i < d.nextIndex; i++)
        {
            this->data[i] = d.data[i];
        }

        nextIndex = d.nextIndex;
        this->capacity = d.capacity;
    }

    void operator=(DynamicArray const &d) // making our very own copy asignment operator.
    {
        // this->data = d.data; // this is default shallow copy by copy construtor and copy asignment operator
        // making a deep copy.
        this->data = new int[d.capacity];
        for (int i = 0; i < d.nextIndex; i++)
        {
            this->data[i] = d.data[i];
        }

        nextIndex = d.nextIndex;
        this->capacity = d.capacity;
    }

    void addElement(int element)
    {
        if (nextIndex == capacity)
        {
            int *newData = new int[2 * capacity]; // ------------Dynamic Array Formation-----------------//
            for (int i = 0; i < capacity; i++) // coping the whole array to newDatass
            {
                newData[i] = data[i];
            }
            delete[] data;  // here we're deleting the old data memory as it is been copied to newData
            data = newData; // making data now to point towards the newData array.
            capacity *= 2;
        }
        data[nextIndex] = element;
        nextIndex++;
    }

    int getElement(int i)
    {
        if (i < nextIndex)
            return data[i];
        else
            return -1; // ternary operator
    }

    void addAtIndex(int i, int el)
    {
        if (i < nextIndex)
        {
            data[i] = el;
        }
        else if (i == nextIndex)
        {
            addElement(el);
        }
        else
        {
            return;
        }
    }

    void print()
    {
        for (int i = 0; i < nextIndex; i++)
        {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};