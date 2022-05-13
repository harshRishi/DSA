#include <cstring>
#include <iostream>
using namespace std;

// Brute Force Solution O(3^n)
int editDistance(string s1, string s2)
{
    // Base Case
    if (s1.empty() || s2.empty())         // both strings are empty
        return max(s1.size(), s2.size()); // In case one of the string overs ?? this means we have to insert all the leftOver element from the remaining string ie. string.size() operationss
    /*
    if (s1.empty() && s2.empty()) // both strings are empty
        return 0;
    // In case one of the string overs ?? this means we have to insert all the leftOver element from the remaining string ie. string.size() operations
    if (s1.empty())
        return s2.length();
    if (s2.empty())
        return s1.length();
    */

    int operations;
    if (s1[0] == s2[0])
        return editDistance(s1.substr(1), s2.substr(1)); // call recurtion on both strings
    else
    {
        // we don't have to change the string we only have to call recusion such that it increases the operation count by 1.
        int insert = 1 + editDistance(s1.substr(1), s2);            // this means we have virtually inserted the 0th char of string s1 to s2;
        int remove = 1 + editDistance(s1, s2.substr(1));            // virtually deleted the 0th char from string s2 and called recusion on s2
        int replace = 1 + editDistance(s1.substr(1), s2.substr(1)); // virtually replaced the 0th char of s2 from s1's 0th char and called recusion on both
        operations = min(insert, min(remove, replace));
    }
    return operations;
}

// Using Memoization O(n) S(n)
int helper(string s, string t, int **output)
{
    int m = s.size(), n = t.size();
    //  Base Case
    if (s.empty() || t.empty())
        return max(s.size(), t.size());

    // check if output already exists
    if (output[m][n] != -1)
        return output[m][n];

    // calc if output isn't calculated already
    int operations;
    if (s[0] == t[0])
        operations = helper(s.substr(1), t.substr(1), output);
    else
    {
        // we don't have to change the string we only have to call recusion such that it increases the operation count by 1.
        int insert = 1 + helper(s.substr(1), t, output);            // this means we have virtually inserted the 0th char of string s to t;
        int remove = 1 + helper(s, t.substr(1), output);            // virtually deleted the 0th char from string t and called recusion on t
        int replace = 1 + helper(s.substr(1), t.substr(1), output); // virtually replaced the 0th char of t from s's 0th char and called recusion on both
        operations = min(insert, min(remove, replace));
    }

    // save the output before returning
    output[m][n] = operations;
    return operations;
}
int editDistance(string s1, string s2)
{
    int m = s1.size(), n = s2.size();
    int **memo = new int *[m + 1]; // created memoization matrix of size m+1 * n+1 and we have initialized it with -1
    for (int i = 0; i < m + 1; i++)
    {
        memo[i] = new int[n + 1];
        for (int j = 0; j < n + 1; j++)
        {
            memo[i][j] = -1;
        }
    }
    return helper(s1, s2, memo);
}

// DP solution O(mn) S(mn)
int editDistance(string s, string t)
{
    // address of last cell in our dp Matrix
    int m = s.length();
    int n = t.length();

    int **dp = new int *[m + 1]; // Our dp Matrix
    for (int i = 0; i < m + 1; i++)
    {
        dp[i] = new int[n + 1];
    }

    // initial values to start with
    for (int i = 0; i < m + 1; i++)
        dp[i][0] = i;
    for (int i = 1; i < n + 1; i++)
        dp[0][i] = i;

    for (int i = 1; i < m + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            int upper = dp[i - 1][j];
            int diagonal = dp[i - 1][j - 1];
            int leftSide = dp[i][j - 1];
            if (s[m - i] == t[n - j])
            {
                dp[i][j] = diagonal;
            }
            else
            {
                dp[i][j] = 1 + min(upper, min(diagonal, leftSide));
            }
        }
    }
    return dp[m][n];
}

int main()
{
    string s1;
    string s2;

    cin >> s1;
    cin >> s2;

    cout << editDistance(s1, s2);
}