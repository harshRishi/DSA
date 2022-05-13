#include <iostream>
using namespace std;

int fact(int n)
{
    if (n == 0)
    {
        return 1;
    }

    int returns = fact(n - 1); // This is called recursion as the function is calling itself to break the problem into smaller segments
    return n * returns;
}

int main()
{
    int n;
    cin >> n;

    cout << fact(n) << endl ;
}