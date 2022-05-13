#include <unordered_map>
int getPairsWithDifferenceK(int *arr, int n, int k)
{
    // Write your code here
    unordered_map<int, int> freq;

    int pairCount = 0;

    for (int i = 0; i < n; i++)
    {
        int complement = arr[i] + k;
        pairCount += freq[complement];

        if (k != 0)
        { //Think about what will happen if k is 0. Then (arr[i] + k) will be equal to (arr[i] – k) and we will print our pairs twice!
            complement = arr[i] - k;
            pairCount += freq[complement];
        }
        freq[arr[i]]++;
    }
    return pairCount;
}
