#include <iostream>
using namespace std;

int fib(int n)
{
    if (n == 0) // fibonacci require two base case to add to form 3rd fibonacci number
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }

    int return1 = fib(n - 1);
    int return2 = fib(n - 2);

    return return1 + return2;
}

int main()
{
    int n;
    cin >> n;
    cout << fib(n) << endl;
}