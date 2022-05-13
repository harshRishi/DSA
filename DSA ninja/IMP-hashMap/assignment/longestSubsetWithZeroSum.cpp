#include <unordered_map>
int lengthOfLongestSubsetWithZeroSum(int *arr, int n)
{
    // Write your code here
    int sum = 0; // initializing sum from 0
    int maxCount = 0;
    unordered_map<int, int> m; // key is sum till jth index and value is index of sum

    for (int i = 0; i < n; i++)
    {
        sum += arr[i]; // add up all the elements from 0th index

        if (arr[i] == 0 && maxCount == 0) // in case we found 0 in bw of sum of prev and current index && maxcount is also 0 than make the maxCount 1 as now we have encountered a subset
            maxCount = 1;
        if (sum == 0) // in case sum is zero even after adding than that means our arr is having multiple 0's in a row ro sum is zero and as sum is zero of all so we need to return there length which is current index + 1;
            maxCount = i + 1;

        if (m.find(sum) != m.end()) // now this find() will return an iterator which if not pointing the end that means we found the item we were looking for
        {
            int count = i - m[sum];
            maxCount = max(maxCount, count);
        }
        else
            m[sum] = i; // key is sum till ith index and value is ith index itself
    }
    return maxCount;
}