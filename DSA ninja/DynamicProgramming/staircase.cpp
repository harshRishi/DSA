#include <iostream>
using namespace std;

// Brute Force
long staircase(int n)
{
    // Base Case
    if (n == 0) // as it is the starting stair
    {
        return 1;
    }
    else if (n < 0) // when n in -ve than return zero
    {
        return 0;
    }
    else // n is greter than 1
    {
        return staircase(n - 1) + staircase(n - 2) + staircase(n - 3); // taking one+two+three steps while climb
    }
}

// Memoization mthod
long helper(int n, int *ans)
{
    // Base Case
    if (n == 0) // as it is the starting stair
        return 1;
    else if (n < 0)
        return 0;
    else
    {
        // made a check if ans to that perticular n already exists
        if (ans[n] != -1)
        {
            return ans[n];
        }

        // otherwise if output doesn't exist, simply calculate
        long one = helper(n - 1);   // one step
        long two = helper(n - 2);   // two step
        long three = helper(n - 3); // three Step

        ans[n] = one + two + three; // save the ans in the ans array for future calc
        return ans[n];              // after saving return
    }
}
long staircase(int n)
{
    int *memo = new int[n + 1];
    for (int i = 0; i <= n; i++)
    {
        memo[i] = -1;
    }
    long result = helper(n, memo);
    delete[] memo;
    return result;
}

// DP
long staircase(int n)
{
    // this will hold our ways to reach n;
    long ans[n + 1];

    /* we need to figure out the first three to use Dp as we're doing n -3 at max*/
    ans[0] = 1; // we know that it is the starting stair and the way to reach it is one
    ans[1] = 1; // if there is one stair than there is only one way ie. 1
    ans[2] = 2; // if there are two stair than we can take 2 stair at a time or one and agaon one ie, 2 ways

    for (int i = 3; i <= n; i++)
    {
        ans[i] = ans[i - 1] + ans[i - 2] + ans[i - 3];
    }
    return ans[n];
}

int main()
{
    int n;
    cin >> n;
    cout << staircase(n);
}