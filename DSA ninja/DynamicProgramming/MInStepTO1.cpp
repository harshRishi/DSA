#include <bits/stdc++.h>
using namespace std;

// DP solution {Best solution O(n) S(n)}
int countMinStep_Dynamic(int n)
{ /*** below array store the minimum steps from ith index to 1 in it's cells***/

    int *minStep = new int[n + 1]; // we taking array size n+1 as we know we need to fin minStep pf n to 1 so 0th index needs to be empty while including the nth
    minStep[1] = 0;                // we stored zero coz steps req from index 1 to digit 1 is zero because it is already there

    for (int i = 2; i <= n; i++)
    {
        int aBy3 = INT_MAX; // taking max int coz'so that we can compare it in min function
        int aBy2 = INT_MAX;

        int a_1 = minStep[i - 1]; // this variable will store steps with -1
        if (i % 3 == 0)
        {
            aBy3 = minStep[i / 3];
        }
        if (i % 2 == 0)
        {
            aBy2 = minStep[i / 2];
        }

        minStep[i] = 1 + min(a_1, min(aBy2, aBy3)); // here we've added 1 coz' we have to include 2 to 1 also
    }
    int result = minStep[n];
    delete[] minStep;
    return result;
}

// Memoization techq. **************************************************************************
int Min_helper(int n, int *ans)
{
    // Base Case
    if (n <= 1)
        return 0;

    // check if any output already exists or not
    if (ans[n] != -1) // if not -1 than ans to the perticular prob already exists
        return ans[n];

    // Calculate output
    int aBy3 = INT_MAX, aBy2 = INT_MAX, a_1 = INT_MAX;
    a_1 = Min_helper(n - 1, ans);

    if (n % 3 == 0)
        aBy3 = Min_helper(n / 3, ans);

    if (n % 2 == 0)
        aBy2 = Min_helper(n / 2, ans);

    int output = 1 + min(a_1, min(aBy2, aBy3)); // by this we'll be able to find the min out of all three;
    ans[n] = output;                            // save output in the ans array

    return ans[n];
}
int countMinStep_2(int n)
{
    int *memo = new int[n + 1];
    for (int i = 0; i <= n; i++)
        memo[i] = -1;

    return Min_helper(n, memo);
}

// Brute Force **********************************************************************
int countMinStepsToOne(int n)
{
    // Write your code here
    //  Base Case
    if (n <= 1)
        return 0;

    int aBy3 = INT_MAX, aBy2 = INT_MAX, a_1 = INT_MAX;
    if (n % 3 == 0)
        aBy3 = countMinStepsToOne(n / 3);

    if (n % 2 == 0)
        aBy2 = countMinStepsToOne(n / 2);

    a_1 = countMinStepsToOne(n - 1);

    return 1 + min(a_1, min(aBy2, aBy3)); // by this we we'll be able to find the min out of all three;
}

int main()
{
    int n;
    cin >> n;
    cout << countMinStepsToOne(n) << endl;
    cout << countMinStep_2(n) << endl;
    cout << countMinStep_Dynamic(n) << endl;
}