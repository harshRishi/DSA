#include <iostream>
using namespace std;

// Brute Force solution O(n ^ n) Very BAD
/*
#include <climits>
int helper(int *arr, int n, int si, int ei, int mini)
{
    // Base Case
    if (si == ei) // this means we have zero matrix
        return 0;
    if (si == ei - 1) // only one matrix therefore no multiplication possible
        return 0;

    // lets take kth element to get top_level brackets
    for (int k = si + 1; k < ei; k++)
    {
        mini = min((helper(arr, n, si, k, mini) + helper(arr, n, k, ei, mini) + (arr[si] * arr[k] * arr[ei])), mini);
    }
    return mini;
}
int matrixChainMultiplication(int *arr, int n) // arr is the array with matrix data ie [a0 * a1][a1*a2] .... as m1 , m2 , m3...
{
    // Write your code here
    // edge case
    if (n == 0 || n == 1) // In both cases multiplication isn't possible asd we either have one or on matrix
        return 0;
    return helper(arr, n, 0, n, INT_MAX);
}
*/

// Using Memoization
#include <climits>
int helper(int *arr, int n, int si, int ei, int mini, int **output)
{
    // Base Case
    if (si == ei || si == ei - 1) // arr either have one or no matrix at all, so 0 multiplication possible
        return 0;

    // check if output already exists
    if (output[si][ei] != -1)
        return output[si][ei];

    // Otherwise calculate the solution
    for (int k = si + 1; k < ei; k++)
    {
        mini = min(helper(arr, n, si, k, mini, output) + helper(arr, n, k, ei, mini, output) + (arr[si] * arr[k] * arr[ei]), mini);
    }

    // before return the solution save it
    output[si][ei] = mini;
    return output[si][ei];
}
int matrixChainMultiplication(int *arr, int n)
{
    // edge case
    if (n == 0 || n == 1) // In both cases multiplication isn't possible asd we either have one or on matrix
        return 0;

    int **memo = new int *[n + 1];
    for (int i = 0; i < n + 1; i++)
    {
        memo[i] = new int[n + 1];
        for (int j = 0; j < n + 1; j++)
            memo[i][j] = -1;
    }
    int ans = helper(arr, n, 0, n, INT_MAX, memo);
    delete[] memo;
    return ans;
}

int matrixChainMultiplication(int *arr, int n)
{
    // Crate a dp array to store the min multiplcation req for startIndex i to endingIndx j
    int **dp = new int *[n + 1];
    for (int i = 0; i < n + 1; i++)
        dp[i] = new int[n + 1];

    // fill the Base case ie, if si == ei, result will be zero as no multiplication i spissible
    for (int i = 1; i < n + 1; i++)
    {
        dp[i][i] = 0;
    }

    // fill remaing dp {l is the chain length}
    for (int l = 2; l < n; l++)
    {
        int j = n - l + 1;
        for (int i)
    }
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];

    for (int i = 0; i <= n; i++)
    {
        cin >> arr[i];
    }

    cout << matrixChainMultiplication(arr, n);

    delete[] arr;
}