#include <iostream>
#include <string>
using namespace std;
/*
// Brute Froce Solution
int solve(string s, string v)
{
    // Base Case
    if (s.empty())
        return 1234; // any large value

    if (v.empty()) // IN this case shorted uncommon substring is single char
        return 1;

    int i;
    for (i = 0; i < v.length(); i++)
    {
        if (s[0] == v[i])
            break;
    }
    // In Case we didn't found char in the given v sting
    if (i == v.length())
        return 1; // this means we found the uncommon char and we can return 1

    // Return minimum of following two Not including current char in answer - Including current char

    //  here i + 1 will call recusion on string v from next to ith index,
    //  as first occurence of the char at s[0] is at the ith position in v and here we're addding 1 as we included the char s[0]
    //  so further occurence will be calc from the ith index

    return min(solve(s.substr(1), v), 1 + solve(s.substr(1), v.substr(i+1)));
}
*/
/*
// Memoization solution
int solve(string s, string v, int **output)
{
    int m = s.length(), n = v.length();
    // Base Case
    if (s.empty())
        return 1234; // any large value

    if (v.empty()) // IN this case shorted uncommon substring is single char
        return 1;

    // check if solution already exists
    if (output[m][n] != -1)
        return output[m][n];

    int i;
    for (i = 0; i < v.length(); i++)
    {
        if (s[0] == v[i])
            break;
    }
    if (i == n)
        return 1;

    // before we return save it in output
    output[m][n] = min(solve(s.substr(1), v, output), 1 + solve(s.substr(1), v.substr(i + 1), output));
    return output[m][n];
}
int solve(string s, string v)
{
    int **memo = new int *[s.length() + 1];
    for (int i = 0; i <= s.lenght(); i++)
    {
        memo[i] = new int[v.length() + 1];
        for (int j = 0; j <= v.length(); j++)
            memo[i][j] = -1;
    }
    int result = solve(s, v, memo);
    delete[] memo;
    return result;
}
*/

// dp solution
#define MAX 12345
int solve(string s, string v)
{
    int m = s.length();
    int n = v.length();
    // Create dp matrix
    int **dp = new int *[m + 1];
    for (int i = 0; i <= m; i++)
    {
        dp[i] = new int[n + 1];
    }

    // In case string V is empty
    for (int i = 0; i <= m; i++) // Base case
        dp[i][0] = 1;

    // In case string S is empty
    for (int i = 1; i <= n; i++) // edge Case
        dp[0][i] = MAX;

    for (int i = 1; i <= m; i++) // string s
    {
        for (int j = 1; j <= n; j++) // string v
        {
            char ch = s[i - 1]; // search ith -1 char of s in v string
            int k;
            for (k = j - 1; k >= 0; k--)
            {
                if (v[k] == ch)
                    break;
            }

            // char not present in V
            if (k == -1)
                dp[i][j] = 1; // this means shortest Subsquence is 1 as char ch isn't even present in the string
            else
            {
                // if k isn't -1 , calc
                int include = dp[i - 1][k] + 1;
                int exclude = dp[i - 1][j];
                dp[i][j] = min(include, exclude);
            }
        }
    }
    int ans = dp[m][n];
    if (ans >= MAX)
        return -1;
    return ans;
}

int main()
{
    string s, v;
    cin >> s >> v;
    cout << solve(s, v);
}