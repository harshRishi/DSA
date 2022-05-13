#include <iostream>
using namespace std;

int staircase(int n)
{
    if (n == 0 || n == 1) // base case
    {
        return 1;
    }
    else if (n == 2) // base case
    {
        return 2;
    }
    else
    {
        return staircase(n - 1) + staircase(n - 2) + staircase(n - 3); // dry run for better under standing 
    }
}

int main()
{
    int n, output;
    cin >> n;
    output = staircase(n);
    cout << output << endl;
}
