#include <bits/stdc++.h>
using namespace std;

// Brute Force
int minCount(int n)
{
    // Base Case
    if (sqrt(n) - floor(sqrt(n)) == 0) // InCase N itself is a perfect Sqaure than simply return one, representing minCount
        return 1;

    if (n <= 3) // minimun square root till 3 are same as that of the number 1^2 +1^2+1^2...
        return n;

    // res is set to be n as n is the maximum count any value of n can get so 1^2 +1^2+1^2... so we'll compare this res with the value returned by recusion
    int res = n;
    for (int i = 1; i < sqrt(n); i++)
    {
        int temp = i * i;
        res = min(res, 1 + minCount(n - temp));
    }
    return res;
}

// Memoization
int helper(int n, int *ans)
{
    // Base Case
    if (sqrt(n) - floor(sqrt(n)) == 0) // InCase N itself is a perfect Sqaure than simply return one, representing minCount
        return 1;

    if (n <= 3) // minimun square root till 3 are same as that of the number 1^2 +1^2+1^2...
        return n;

    // res is set to be n as n is the maximum count any value of n can get so 1^2 +1^2+1^2... so we'll compare this res with the value returned by recusion
    int res = n;
    for (int i = 1; i < sqrt(n); i++)
    {
        int temp = i * i;
        // check if output already exist
        if (ans[n] != -1)
            return ans[n];
        else // calc the ans
        {
            res = min(res, 1 + helper(n - temp, ans)); // here we'll recieve the min count as we have compared it with max possible count
            ans[n] = res;                              // here we're storing the min number of sqrt for n
        }
    }
    return ans[n]; // after saving return it.
}
int minCount(int n)
{
    int *memo = new int[n + 1];
    for (int i = 0; i <= n; i++)
        memo[i] = -1;

    int result = helper(n, memo);
    delete[] memo;
    return result;
}

// DP
int minCount(int n)
{
    // this array will store min Count of sqrt to achieve ith number
    int ans[n + 1]; // dp array

    /* ALl number from 0-3 are having same number of MinCount as there value*/
    ans[0] = 0;
    ans[1] = 1;
    ans[2] = 2;
    ans[3] = 3;

    for (int i = 4; i <= n; i++)
    {
        // res is set to be i as i is the maximum count any value of n can get so 1^2 +1^2+1^2... so we'll compare this res with the value samller if possible trough iteration
        ans[i] = i;
        for (int j = 1; j <= ceil(sqrt(n)); j++) // ceil is basically same as floor except this will make roundOff to higher values
        {
            int temp = j * j;

            if (temp > i) // no need to cross the current value of i (that is current n)
                break;

            ans[i] = min(ans[i], 1 + ans[i - temp]);
        }
    }
    return ans[n];
}

int main()
{
    int n;
    cin >> n;
    cout << minCount(n);
}