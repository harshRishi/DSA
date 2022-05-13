#include <iostream>
using namespace std;
#include <vector>

class PriorityQueue
{ // our Data members
    vector<int> pq;

public:
    // constructor
    PriorityQueue()
    {
    }

    // Our Public Functions ==========================
    bool isEmpty()
    {
        return pq.size() == 0;
    }

    int getSize() // this will return total number of elements in the prioritQueue
    {
        return pq.size();
    }

    int getMin()
    {
        if (this->isEmpty())
        {
            return 0; // incase priorityQueue is empty
        }

        return pq.at(0);
    }

    // imagine this as a Binary Tree (Complete Binary Tree)
    void insert(int element)
    {
        // here we've inserted the element into the CBT but at this point it might not satisfy the heap order.
        pq.push_back(element);

        int childIndex = pq.size() - 1; // this will going to give us index of child

        while (childIndex > 0)
        {
            int parentIndex = (childIndex - 1) / 2; // this will goin' to give us the parent index

            // swapped the parent with it's child if child data is smaller than parent data as at the root of the CBT only the smallest stand
            if (pq.at(childIndex) < pq.at(parentIndex))
            {
                int temp = pq.at(childIndex);
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            }
            else // break the loop if current root of CBT is smaller than it's corresponting child
            {
                break;
            }
            // child is now pointing at the parent for further swaps
            childIndex = parentIndex;
        }
    }

    int removeMin()
    {
        // Write your code here
        if (this->isEmpty()) // if priorityQueue is Empty than simply return 0
            return 0;

        int ans = pq[0];
        // index of last element i.e largest element
        pq[0] = pq[pq.size() - 1];
        pq.pop_back();

        int parentIndex = 0;
        int lChildIndex = 2 * parentIndex + 1, rChildIndex = 2 * parentIndex + 2;
        while (lChildIndex < pq.size()) // if lChild is out of the range than rChild is obvio out as well
        {
            int minIndex = parentIndex;

            // now lets figure out who's minimum out of three( parent lchild and rchild )
            if (pq.at(minIndex) > pq.at(lChildIndex))
            {
                minIndex = lChildIndex;
            }
            // here we should check weather rChild is there or not and if it is,  than check weather it smaller our vector size(priorityQueue size)
            if (rChildIndex < pq.size() && pq.at(minIndex) > pq.at(rChildIndex))
            {
                minIndex = rChildIndex;
            }

            // check: if minindex is still pointing towards parent than that means our data reached it's correct position
            if (minIndex == parentIndex)
                break;

            // by this [point] we know minIndex is actually pointinfg towards the min value block
            // perform swap bt min and parent
            int temp = pq.at(minIndex);
            pq[minIndex] = pq.at(parentIndex); // placed parent in min's position
            pq[parentIndex] = temp;            // placed min at parent's position

            parentIndex = minIndex; // now for further iterations we've updated the min index to be parentIndex
            lChildIndex = 2 * parentIndex + 1;
            rChildIndex = 2 * parentIndex + 2;
        }
        return ans; // return the value which is been popped out of the priority queue
    }
};