bool isMaxHeap(int arr[], int n)
{
    // Write your code here
    for (int i = 0; i < n; i++) // here we're check weather the parent is larger than it's childor not if not return false
    { // parent Index is considered as i
        int lChildIndex = 2 * i + 1;
        int rChildIndex = 2 * i + 2;

        if (lChildIndex < n)
        {
            if (arr[i] < arr[lChildIndex] || arr[i] < arr[rChildIndex])
            {
                return false;
            }
        }
    }
    return true;
}