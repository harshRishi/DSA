#include <iostream>
using namespace std;

/* // Method 1 {TimeComplexcity O(2^n) very Bad - exponential}
int fibo(int n)
{
    // Base Case
    if (n <= 1)
    {
        return n; // here we're asking for the nth fibonacci number in recusion
    }

    int a = fibo(n - 1);
    int b = fibo(n - 2);
    return a + b;
}
*/

// method 2 TIME COMPLEXCITy O(n)
/* Approch [Using Memoization method] - Top/down Approch
{
    - here to avoid the unnessasery calls we  made a array that will store fibonacci's nth number
}
*/
int fibo(int n, int *ans)
{
    // Base Case
    if (n <= 1)
        return n; // here we're asking for the nth fibonacci number in recusion

    // check weather output already exists {ie. fibonacci already exists and we dont need to call recusion on that perticular number}
    if (ans[n] != -1)
    {
        return ans[n]; // as this number already been calculated we just need to return when required
    }

    // Recusive call
    int a = fibo(n - 1, ans);
    int b = fibo(n - 2, ans);

    // if not calculated than calculated and save it the array
    ans[n] = a + b;

    return ans[n]; // return the final output
}

// Using Dynamic Programmigng [bottom / up]
int fibo_dynamic(int n)
{
    int *ans = new int[n + 1]; // this array will store the series
    // we know first two positions
    ans[0] = 0;
    ans[1] = 1;

    for (int i = 2; i <= n; i++) // i starts from 2 as 0th and 1st are already been taken care
    {
        ans[i] = ans[i - 1] + ans[i - 2]; // add previous 2 digits from the array to find the current one
    }
    // by this point out nth position will store the nth fibonacci number
    return ans[n];
}

int main()
{
    int n;
    cin >> n;

    int *ans = new int[n + 1]; // as we have to store till n different numbers
    for (int i = 0; i < n + 1; i++)
    {
        ans[i] = -1;
    }

    cout << "Dynamic Program: " << fibo_dynamic(n) << endl;
    cout << "Memoization program: " << fibo(n, ans) << endl;
}