#include <bits/stdc++.h>
using namespace std;

// ***************************************   Brute Force solution  *************************************** O(3^n || 3^m)
/*
int minCost(int **input, int m, int n, int i, int j)
{ // i , j are co-ordinates
    // Base case
    if (i == m - 1 && j == n - 1)
        return input[i][j];

    // In Case one of both row or Col reached it's limits ie. i == m-1 and j != n-1 OR vise versa
    if (i >= m || j >= n)
        return INT_MAX; // we have returned max so that when we calc minimun out of x,y,z we don't select this as an ans

    // Recursive calls
    int x = minCost(input, m, n, i, j + 1);     // column traversal
    int y = minCost(input, m, n, i + 1, j + 1); // diagonal
    int z = minCost(input, m, n, i + 1, j);     // row

    // Small Calculation
    int ans = min(x, min(y, z)) + input[i][j]; // select min out of three and add current index data to it
    return ans;
}
int minCostPath(int **input, int m, int n)
{
    // Write your code here
    return minCost(input, m, n, 0, 0);
}
*/

//  *************************** Using Memoization ****************************************** O(n || m) && S(n || m)
/*
int helper(int **input, int m, int n, int i, int j, int **output)
{
    // Base case
    if (i == m - 1 && j == n - 1)
        return input[i][j]; // as we're in the last cell that means minCost is it's value as starting and ending are same

    // In Case one of both row or Col reached it's limits ie. i == m-1 and j != n-1 OR vise versa
    if (i >= m || j >= n)
        return INT_MAX; // we have returned max so that when we calc minimun out of x,y,z we don't select this as an ans

    // check if this i, j alread have the output or not
    if (output[i][j] != -1)
        return output[i][j]; // return the corresponding path

    // Recursive calls
    int x = helper(input, m, n, i, j + 1, output);     // column traversal
    int y = helper(input, m, n, i + 1, j + 1, output); // diagonal
    int z = helper(input, m, n, i + 1, j, output);     // row

    int ans = min(x, min(y, z)) + input[i][j];

    // before returning save this in output for further checks
    output[i][j] = ans;
    return output[i][j];
}
int minCostPath(int **input, int m, int n)
{
    int **output = new int *[m];
    for (int i = 0; i < m; i++)
    {
        output[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            output[i][j] = -1;
        }
    }
    return helper(input, m, n, 0, 0, output);
}
*/

// ********************************  DP *********************************** O(n || m) best Solution
int minCostPath(int **input, int m, int n)
{
    // Make the dp matrix as here we need that to store the ans
    int **dp = new int *[m];
    for (int i = 0; i < m; i++)
    {
        dp[i] = new int[n];
    }

    // we know we've start from the last cell in the matrix as in memoization also we're filling frm last cell and our ans is in the first cell
    dp[m - 1][n - 1] = input[m - 1][n - 1]; // last cell have same value as it store and it's minCost will be same as starting and ending are same

    for (int j = n - 2; j >= 0; j--) // Column check where row is fixed
    {                                // n -2 as n -1 is the last cell
        dp[m - 1][j] = input[m - 1][j] + dp[m - 1][j + 1];
    }
    for (int i = m - 2; i >= 0; i--) // row check where column is fixed
    {
        dp[i][n - 1] = dp[i + 1][n - 1] + input[i][n - 1];
    }

    // till this we've have filled the last row and column from bottom to top and right to left
    // now fill the complete dp matrix for remaing cells by picking up the min value of right left and diagonal
    for (int i = m - 2; i >= 0; i--) // maintaining row
    {
        for (int j = n - 2; j >= 0; j--) // maintinging column
        {
            /*
            // row calc
            int x = dp[i][j + 1] + input[i][j];
            // diagonal calc
            int z = dp[i + 1][j + 1] + input[i][j];
            // col calc
            int y = dp[i + 1][j] + input[i][j];

            dp[i][j] = min(x, min(y, z));
            */

            // above line =========== OR ============= ??
            dp[i][j] = input[i][j] + min(dp[i][j + 1], min(dp[i + 1][j + 1], dp[i + 1][j]));
        }
    }

    return dp[0][0]; // minCost from (0,0) to (m-1, n-1)
}

int main()
{
    int **arr, n, m;
    cin >> n >> m;
    arr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[m];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    cout << minCostPath(arr, n, m) << endl;
}