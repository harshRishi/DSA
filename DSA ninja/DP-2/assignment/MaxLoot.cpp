/*
// Brute Force Solution
int maxMoneyLooted(int *arr, int n)
{
    //Write your code here
    if(n <= 0)
        return 0;

    int taken = arr[0] + maxMoneyLooted(arr+2, n-2);
    int notTaken = maxMoneyLooted(arr+1, n-1);

    return max(taken, notTaken);
}
*/
// Dynamic Progm Solution
int maxMoneyLooted(int *arr, int n)
{
    // Write your code here
    //  this dp array will going to store maxSum till ith index
    int dp[n + 1]; // size of dp can have this possible different cases

    // we know that
    dp[0] = arr[0];             // consider including 0th element
    dp[1] = max(dp[0], arr[1]); // not taken the first element so we've to take max till 1st index excluding 0th index

    for (int i = 2; i <= n; i++)
    {
        /*
        {
        - to fill ith index we need to find i-2th and i -1  (as this address already know maxSUm till i -2  and i -1)
        - here we consider both cases including arr's ith element and also excluding
        - max of including and excluding will be stored at dp[i];
        }
        */
        int include = dp[i - 2] + arr[i];
        int exclude = dp[i - 1];
        dp[i] = max(include, exclude);
    }
    return dp[n - 1];
}
