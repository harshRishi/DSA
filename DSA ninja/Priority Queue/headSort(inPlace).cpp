/* Approch */
/*
- first make the given arr a heap;
{
    - for that we need do up-heapification
    - make do child-parent shifts
    - until we made a heap of the whole array
}
- than use down heapify using a similar function as that of removeMin in PriorityQueue remove funtion
{
    - swap first and last element of the head
    - before moving ahead save initial arr size(i.e n) into a int size variable. than after first last swap decrese the size by 1, so as we know that last element is now at it's correct position
    - than down heapify the top element to it's corresponding location
}
*/

void heapSort(int arr[], int n)
{
    // first build the heap in arr itself ??
    int i = 1; // initializing unsorted array as we've considered the 0th element to be sorted or in correct position
    for (; i < n; i++)
    {
        int childIndex = i;
        while (childIndex > 0) // run until we reach root node or simply 0th index
        {
            int parentIndex = (childIndex - 1) / 2;
            if (arr[childIndex] < arr[parentIndex])
            { // simply swap the child with parent if child is smaller
                int temp = arr[parentIndex];
                arr[parentIndex] = arr[childIndex];
                arr[childIndex] = temp;
            }
            else // break if current child reach the correct position
            {
                break;
            }
            childIndex = parentIndex;
        }
    }

    // Remove Elements ?? down heapIfy
    int size = n;
    while (size > 1)
    {
        int ans = arr[0]; //saved first element of the array
        arr[0] = arr[size - 1];
        arr[size - 1] = ans;
        size--;

        int parentIndex = 0;
        int lChildIndex = 2 * parentIndex + 1, rChildIndex = 2 * parentIndex + 2;
        while (lChildIndex < size)
        {
            int minIndex = parentIndex;
            if (arr[minIndex] > arr[lChildIndex])
            {
                minIndex = lChildIndex;
            }
            if (rChildIndex < size && arr[minIndex] > arr[rChildIndex])
            {
                minIndex = rChildIndex;
            }

            if (minIndex == parentIndex) // this means after down heapification the parent reached the corret position and thus we dont need to down heapify it to the leafNode or till the end
            {
                break;
            }
            // ferForm the swap
            int temp = arr[minIndex];
            arr[minIndex] = arr[parentIndex];
            arr[parentIndex] = temp;

            // for futher down-heapification
            parentIndex = minIndex;
            lChildIndex = 2 * parentIndex + 1;
            rChildIndex = 2 * parentIndex + 2;
        }
    }
}