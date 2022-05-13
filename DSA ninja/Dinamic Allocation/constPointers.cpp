#include <iostream>
using namespace std;

void g(int const &f)
{
    // f++; // As it is a read Only access
}

void f(int const *p)
{
    // (*p)++; // we Can't do this. have read Only Access
}

int main()
{
    int const i = 10;
    int const *p = &i; // Here the main variable dont have access to write that the pointer need to be const as well to get read only access

    int j = 123;
    const int *p2 = &j;

    j++;
    cout << *p2 << endl;

    f(&j);
    cout << j << endl;

    g(j);
    cout << j << endl;
}