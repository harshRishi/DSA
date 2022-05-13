#include <iostream>
using namespace std;
#include <vector>

class PriorityQueue
{
    // Declare the data members here
    vector<int> pq;

public:
    PriorityQueue()
    {
        // Implement the constructor here
    }

    /**************** Implement all the public functions here ***************/
    bool isEmpty()
    {
        // Implement the isEmpty() function here
        return pq.size() == 0;
    }

    int getSize()
    {
        // Implement the getSize() function here
        return pq.size();
    }

    int getMax()
    {
        if (this->isEmpty())
            return 0;
        // Implement the getMax() function here
        return pq.at(0);
    }

    void insert(int element)
    {
        // Implement the insert() function here
        pq.push_back(element);

        int childIndex = pq.size() - 1; // basiclly last

        while (childIndex > 0) //  run untill we reach the 0th index i.e root node
        {
            int parentIndex = (childIndex - 1) / 2; // this will give us parent index of that perticular child
            if (pq.at(childIndex) > pq.at(parentIndex))
            { // parent child swap
                int temp = pq.at(parentIndex);
                pq[parentIndex] = pq.at(childIndex);
                pq[childIndex] = temp;
            }
            else // break the loop if current root(parent) of CBT is larger than it's corresponting child
            {
                break;
            }
            // child is now pointing at the parent for further swaps
            childIndex = parentIndex;
        }
    }

    int removeMax()
    {
        // Implement the removeMax() function here
        int ans = pq.at(0);

        // swap the last and the first elements
        pq[0] = pq.at(pq.size() - 1);
        pq.pop_back();

        int parentIndex = 0;
        int lChildIndex = (2 * parentIndex) + 1, rChildIndex = (2 * parentIndex) + 2;

        while (lChildIndex < pq.size())
        {
            int maxIndex = parentIndex;

            if (pq.at(maxIndex) < pq.at(lChildIndex))
                maxIndex = lChildIndex;
            if (rChildIndex < pq.size() && pq.at(maxIndex) < pq.at(rChildIndex))
                maxIndex = rChildIndex;

            if (maxIndex == parentIndex)
                break;

            int temp = pq.at(parentIndex);
            pq[parentIndex] = pq.at(maxIndex);
            pq[maxIndex] = temp;

            // for further iteration
            parentIndex = maxIndex;
            lChildIndex = (2 * parentIndex) + 1;
            rChildIndex = (2 * parentIndex) + 2;
        }
        return ans;
    }
};