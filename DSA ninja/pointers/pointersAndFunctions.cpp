#include <iostream>
using namespace std;

void print(int *p)
{
    cout << *p << endl;
}

void incrementPointer(int *p) // here the value of p is passed not p so there will be no change in the output in the main function
{
    p = p + 1;
}

void incrementValue(int *p) // here also p value is just passed not p itself.
{
    (*p)++; // but here after creating the p in this function this p will also point the same location as that of the main () p so both are pointing towards the same storage and any change will affact the i which is in the main function
}

int main()
{
    int i = 10;
    // cout << addressof(i) << endl;
    int *p = &i;

    print(p);

    cout << p << endl;
    incrementPointer(p);
    cout << p << endl;

    cout << *p << endl;
    incrementValue(p);
    cout << *p << endl;
}