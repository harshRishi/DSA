#include <bits/stdc++.h>
using namespace std;
int findMaxSquareWithAllZeros(int **arr, int n, int m)
{
    // Create a dp matrix
    int **dp = new int *[n + 1];
    for (int i = 0; i < n + 1; i++)
    {
        dp[i] = new int[m + 1];
    }
    //  fill the Base Case
    /*
    {
        - fill first row and col with 0 if original arr have 1 at that same index
        - fill first row and col with 1 if original arr have 0 at that same index
    }
    */
    for (int i = 0; i < n; i++)
    {
        if (arr[i][0] == 0)
            dp[i][0] = 1;
        else
            dp[i][0] = 0;
    }
    for (int i = 1; i < m; i++)
    {
        if (arr[0][i] == 0)
            dp[0][i] = 1;
        else
            dp[0][i] = 0;
    }

    // for(int i =0 ; i < n; i++)
    // {
    //     for(int j = 0; j < m; j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    /*
    {
        - Now to find max square with all zeros till ith and jth index
        - compare the uper, side left and diagonal cell and +1 to the min of all three, Reason :
        {
            - As upper will going to have the data of max square with all zeros till that indexes
            - so as goes for side left and diagonal cells
            - therefore min of all three with +1 will give square with all zero to the current indexs
        }
    }
    */
    int result = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            int upper = dp[i - 1][j];
            int diagonal = dp[i - 1][j - 1];
            int sideLeft = dp[i][j - 1];
            // cout <<  upper << " " << diagonal <<  " " << sideLeft << endl;
            if (arr[i][j] == 0) // we should calc it's max sqaure
            {
                dp[i][j] = 1 + min({upper, diagonal, sideLeft});
            }
            else
            {
                dp[i][j] = 0;
            }
            result = max({result, dp[i][j]});
        }
    }
    // int result = dp[n][m];
    delete[] dp;
    return result;
}