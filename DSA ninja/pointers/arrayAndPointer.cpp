#include <iostream>
using namespace std;

int main()
{
    int a[10];
    cout << a << endl;
    cout << &a[0] << endl;

    a[0] = 5; // *a
    a[1] = 10; // *(a + 1)

    cout << "Value Using *(a + i)" << endl;
    cout << *a << endl;
    cout << *(a + 1) << endl;

    int *p = &a[0];

    cout << "P is basically pointing towards memory location of a" << endl;
    cout << a << endl;
    cout << p << endl;

    cout << "Memory location of a and p" << endl;
    cout << &a << endl; // memory location of a and here a is basically location of a[0]
    cout << &p << endl; // memory location of p i.e diffrent from the memory location of a.

    cout << "Size of a and p" << endl;
    cout << sizeof(a) << endl;
    cout << sizeof(p) << endl;

    cout << p = p + 1 << endl; // this will point the next element of the array i.e a[1]

    // a = a +1; while this is not valid coz arrays can not be reasigned again.
}