#include <iostream>
using namespace std;
#include "OP1.cpp"

int main()
{
    Fraction f1(10, 2);
    Fraction f2(15, 4);
    Fraction f6(10, 2);

    Fraction f3 = f1.add(f2);
    Fraction f4 = f3 + f2; // Using Operator overloadin
    Fraction f5 = f1 * f2; // Using Operator overloadin
    f1.print();
    f2.print();
    f3.print();
    f4.print();

    // TERNARY OPERATOR
    f6 == f2 ? cout << "Equal" << endl : cout << "Not equal" << endl; // Using Operator overloadin
    f6 == f1 ? cout << "Equal" << endl : cout << "Not equal" << endl; // Using Operator overloadin
}
