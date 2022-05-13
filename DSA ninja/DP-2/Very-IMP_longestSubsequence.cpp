#include <iostream>
#include <string>
using namespace std;

// Longest common sequence
//=================== Brute Force solution
int lcs(string s, string t)
{
    // Base Case
    if (s.empty() || t.empty()) // In case one of the given string is empty so longest common sequence possible is zero
        return 0;

    // small Calc
    if (s[0] == t[0])
    {
        return 1 + lcs(s.substr(1), t.substr(1)); // move one ahead in both strings as char of there 0th index matched
    }

    // recursive Calls
    // return max(lcs(s.substr(1), t), max(lcs(s, t.substr(1)), lcs(s.substr(1), t.substr(1)))); // here case ie removing both string's first char is not need as it is already been handled inside recusion
    // +++++++++ OR
    return max(lcs(s.substr(1), t), lcs(s, t.substr(1))); // recusion on s string and than on t string
}

// Using Memoization
int lcs_memo(string s, string t, int **output)
{
    int m = s.length();
    int n = t.length();

    // Base Case
    if (s.empty() || t.empty()) // In case one of the given string is empty so longest common sequence possible is zero
        return 0;

    // check if output already exists
    if (output[m][n] != -1)
        return output[m][n]; // now this output Matrix store the lcs of string from the index ie, for output[i][j]  there will be lcs of s.substr(i) && t.substr(j)

    // small Calc
    int ans;
    if (s[0] == t[0])
        ans = 1 + lcs_memo(s.substr(1), t.substr(1), output); // move one ahead in both strings as char of there 0th index matched
    else
    {
        // Our recusive call on first string than on second string
        int first = lcs_memo(s.substr(1), t, output);
        int second = lcs_memo(s, t.substr(1), output);
        ans = max(first, second);
    }
    // save it in the output for future checks
    output[m][n] = ans;
    return ans; // return after saving
}

// DynamicProgramming Solution
int lcs_dp(string s, string t)
{
    // address of last cell in our dp Matrix
    int m = s.length();
    int n = t.length();

    // create a dynamic progam Matrix of size m+1 * n+1, as all possible combination for m is [0-n] and so as for n
    int **dp = new int *[m + 1];
    for (int i = 0; i < m + 1; i++)
    {
        dp[i] = new int[n + 1];
    }

    /*{
        - Filler 0th row and 0th Column with Zero.. reason-{
            -To calculate lcs of any cell we need to know three values those are {
                1. cell's upper cell lcs
                2. cell's left cell lcs
                3. cell's uppr diagonal lcs
            }
            - in Case we of 0th row and col we dont have upper cell and upper diagonal lcs so we can actuall put zero there.
            - now if string 0th char matches than all we need to do it fill current cell with 1 + max(of all three upper, diagonal and side left cell)
            - if doesn't match simply fill currnt cell with max(all three) without adding one
            - thereBY are ans will be on the last cell ie, dp[m][n]
        }
    }*/
    // fill the 0th row and col with zero
    for (int i = 0; i <= m; i++)
    { // rows will change in 0th column
        dp[i][0] = 0;
    }
    for (int i = 1; i <= n; i++)
    { // columns will change in 0th row
        dp[0][i] = 0;
    }

    // fill rest of the cells
    /*VERY IMP - here i and j represent length of the strings respectively*/ // caution while matching the first char of the string, line [103]
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            // cells to be used in calc
            int upper = dp[i - 1][j];
            int diagonal = dp[i - 1][j - 1];
            int leftSide = dp[i][j - 1];
            // if char at 0th index of string s matches char at 0th index of string t.
            if (s[m - i /*remaining string length*/] == t[n - j /*remaining string length*/]) // Now this will give us the char we need to compare
            {
                int ans = 1 + diagonal;
                dp[i][j] = ans;
            }
            else
            {
                int ans = max(upper, max(diagonal, leftSide));
                dp[i][j] = ans;
            }
        }
    }
    return dp[m][n];
}

int main()
{
    string s, t;
    cin >> s >> t;

    int m = s.length(), n = t.length();
    // creted a 2d matrix of size m+1 * n+1;
    int **memo = new int *[m + 1]; // this matrix will
    for (int i = 0; i < m + 1; i++)
    {
        memo[i] = new int[n + 1];
        for (int j = 0; j < n + 1; j++)
            memo[i][j] = -1; // Marked it un-used by setting -1 in all of the cells initailly
    }

    cout << "Brute Force " << lcs(s, t) << endl;
    cout << "DP " << lcs_dp(s, t) << endl;
    cout << "Memoization " << lcs_memo(s, t, memo) << endl;
    delete[] memo;
}