#include <bits/stdc++.h>
using namespace std;

int helper(int *a, int n, int sum, int tar)
{
    if (n == 0 && tar == sum)
    {
        return 1;
    }
    if (n < 0)
    {
        return 0;
    }
    int one = helper(a + 1, n - 1, sum, tar + a[0]);
    int two = helper(a + 1, n - 1, sum, tar);
    return one + two;
}

int main()
{

    // write your code here
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int sum;
        cin >> sum;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        cout << helper(a, n, sum, 0) << endl;
    }

    return 0;
}