/*
// Brute force
int countWaysToMakeChange(int coins[], int numCoin, int value)
{
    if (value == 0) // If numCoin is 0 then there is 1 solution (do not include any coin)
        return 1;

    // If numCoin is less than 0 then no - solution exists
    if (value < 0)
        return 0;

    // If numCoin is less than 0 then no-solution exists
    if (numCoin <= 0 && value > 0)
        return 0;

    // count is sum of solutions, including S[m-1] && excluding S[m-1]
    return countWaysToMakeChange(coins, numCoin, value - coins[0]) + countWaysToMakeChange(coins, numCoin - 1, value);
}
*/
/*
// Using memoization
int helper(int coins[], int n, int v, int **output)
{
    if (v == 0) // If n is 0 then there is 1 solution (do not include any coin)
        return output[n][v] = 1;

    // If n is less than 0 then no - solution exists
    if (n == 0)
        return 0;

    // check if solution already exists
    if (output[n][v] != -1)
        return output[n][v];

    if (coins[n - 1] <= v)
    {
        // save it and than return
        return output[n][v] = helper(coins, n, v - coins[n - 1], output) + helper(coins, n - 1, v, output); // including and excluding
    }
    else // We have no option but to leave this coin
        return output[n][v] = helper(coins, n - 1, v, output);
}
int countWaysToMakeChange(int coins[], int numCoin, int value)
{
    // Our memoization array
    int **memo = new int *[numCoin + 1];
    for (int i = 0; i < numCoin + 1; i++)
    {
        memo[i] = new int[value + 1];
        for (int j = 0; j < value + 1; j++)
            memo[i][j] = -1;
    }
    return helper(coins, numCoin, value, memo);
}
*/

// Dynamic Program SOlution
int countWaysToMakeChange(int S[], int m, int n)
{
    int i, j, x, y;

    // We need n+1 rows as the table
    // is constructed in bottom up
    // manner using the base case 0
    // value case (n = 0)
    int table[n + 1][m];

    // Fill the entries for 0
    // value case (n = 0)
    for (i = 0; i < m; i++)
        table[0][i] = 1;

    // Fill rest of the table entries
    // in bottom up manner
    for (i = 1; i < n + 1; i++)
    {
        for (j = 0; j < m; j++)
        {
            // Count of solutions including S[j]
            x = (i - S[j] >= 0) ? table[i - S[j]][j] : 0;

            // Count of solutions excluding S[j]
            y = (j >= 1) ? table[i][j - 1] : 0;

            // total count
            table[i][j] = x + y;
        }
    }
    return table[n][m - 1];
}