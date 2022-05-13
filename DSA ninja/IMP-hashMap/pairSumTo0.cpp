/* method 1
#include <unordered_map>
int pairSum(int *arr, int n)
{
    // Write your code here
    int ans = 0;
    unordered_map<int, int> findPair;
    for (int i = 0; i < n; i++)
        findPair[arr[i]]++; // increase it's freq if found, else store default and increase it by 1s

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0) // incase we have multiple zeros [ncm] ie, like we have five zeros and we need to make pair so all posible cases are 5 c 2
        {
            int cur = findPair[arr[i]];
            ans += (cur * (cur - 1)) / 2;
            findPair[arr[i]] = 0;
            continue;
        }
        int term = -arr[i];
        if (findPair[term] > 0) // if we found freq is one
        {
            if (findPair[term] > 1) // if freq is more than one
            {
                if (findPair[arr[i]] > 1) // if both +ve and -ve are having freq more than 1
                {
                    // make pair with -ve * +ve freq and than set both of there freq to zero
                    ans += (findPair[arr[i]] * findPair[term]);
                    findPair[term] = 0;
                    findPair[arr[i]] = 0;
                    continue;
                }
                // make pair with each -ve term and than set -ve's freq 0;
                ans += findPair[term];
                findPair[term] = 0;
                findPair[arr[i]]--;
                continue;
            }
            ans++;
            findPair[arr[i]]--;
            findPair[term]--;
        }
    }
    return ans;
}
*/

// method 2

#include <bits/stdc++.h>
using namespace std;
int pairSum(int *arr, int n)
{
    int ans = 0;
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        int rem = -arr[i];
        ans += m[rem];
        m[arr[i]]++;
    }
    return ans;
}