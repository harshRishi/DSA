#include <iostream>
using namespace std;
/*
//========================================== Brute Force solution ========================================
int knapsack(int *weights, int *values, int n, int maxWeight)
{
    // Base Case
    if (n == 0 || maxWeight == 0)
        return 0;

    if (weights[0] > maxWeight) // bofore including this weight check weather is or not larger weight then maxWeight
        return knapsack(weights + 1, values + 1, n - 1, maxWeight);

    // recusive call
    int taken = values[0] + knapsack(weights + 1, values + 1, n - 1, maxWeight - weights[0]);
    int notTaken = knapsack(weights + 1, values + 1, n - 1, maxWeight);

    // now return the max of both taken and not taken
    return max(taken, notTaken);
}
*/
// ====================================== Memoization solution ===========================================
/* Approch
{
    - Here we need a 2d matrix of size n * maxWeight
    - here in this matrix we will going to store the maxCost or MaxValue for n size of array with maxWeight {here output[n][maxW] will have the maxValue for n size arry of weights with maxWeight Capacity}
    - here we've saved the ans in our matrix if we that state again simply return the found value as it is already been calculated erlier
    - if not found the maxCost for this n size weight arr with this maxWeight simply call recusion
    - than save this ans at (n , maxWeight) with maxCost value
    - than return that output[n][maxWeight]
}
*/
int helper(int *weights, int *values, int n, int maxWeight, int **output)
{
    // Base Case
    if (n <= 0 || maxWeight <= 0)
        return 0;

    // check if output already exists
    if (output[n][maxWeight] != -1)
        return output[n][maxWeight];

    // bofore including this weight check weather is or not larger weight then maxWeight
    if (weights[0] > maxWeight)
    {
        output[n][maxWeight] = helper(weights + 1, values + 1, n - 1, maxWeight, output);
        return output[n][maxWeight];
    }
    // recusive calls
    int taken = values[0] + helper(weights + 1, values + 1, n - 1, maxWeight - weights[0], output);
    int notTaken = helper(weights + 1, values + 1, n - 1, maxWeight, output);

    // Save the ans before returning
    output[n][maxWeight] = max(taken, notTaken);
    return output[n][maxWeight];
}
int knapsack(int *weights, int *values, int n, int maxWeight)
{
    int **memo = new int *[n + 1]; // created a 2d Matrix of size n * maxWeight
    for (int i = 0; i < n + 1; i++)
    {
        memo[i] = new int[maxWeight + 1];
        for (int j = 0; j < maxWeight + 1; j++)
            memo[i][j] = -1;
    }
    int result = helper(weights, values, n, maxWeight, memo);
    delete[] memo;
    return result;
}

// ============================= Dynamic Programming ==============================
#include <vector>
int knapsack(int *weights, int *values, int n, int maxWeight)
{
    // Create a dp Matrix for this problem
    vector<vector<int>> dp(2, vector<int>(maxWeight + 1, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= maxWeight; j++)
        {
            if (weights[i] <= j) // if taken
                dp[i % 2][j] = max(values[i] + dp[(i + 1) % 2][j - weights[i]], dp[(i + 1) % 2][j]);

            else // not taken
                dp[i % 2][j] = dp[(i + 1) % 2][j];
        }
    }
    return dp[(n + 1) % 2][maxWeight];
}

int main()
{
    int n;
    cin >> n;

    int *weights = new int[n];
    int *values = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> weights[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> values[i];
    }

    int maxWeight;
    cin >> maxWeight;

    cout << knapsack(weights, values, n, maxWeight) << endl;

    delete[] weights;
    delete[] values;
}