#include <iostream>
using namespace std;

int main()
{
    int i = 10;

    int *p = &i;
    int **p2 = &p;

    // cout << &p << endl;
    // cout << &p2 << endl;

    cout << "Location of p" << endl;
    cout << p2 << endl;
    cout << &p << endl;

    cout << "location of i" << endl;
    cout << p << endl;
    cout << *p2 << endl;

    cout << "Value of i" << endl;
    cout << &i << endl;
    cout << *p << endl;
    cout << **p2 << endl;
}