#include <iostream>
using namespace std;
#include "OP3.cpp"

int main()
{
    Fraction f1(10, 2);
    Fraction f2(15, 4);
    Fraction f6(10, 2);

    (f1 += f2) += f2;
    f1.print();
    f2.print();

    /*
    Fraction fNew = f1++;
    fNew.print();
    f1.print();

    f1 += f2;
    f1.print();
    f2.print();
    */
   
    /*
    f1.print();
    ++f1;
    f1.print();

    Fraction f7 = ++f1; // calling copy construtor
    f7.print();

    Fraction f8 = ++(++f1); // see class file important concept
    f8.print();

    */

    /*
    Fraction f3 = f1.add(f2);
    Fraction f4 = f3 + f2;
    Fraction f5 = f1 * f2;
    f1.print();
    f2.print();
    f3.print();
    f4.print();

    f6 == f2 ? cout << "Equal" << endl : cout << "Not equal" << endl; // TERNARY OPERATOR
    f6 == f1 ? cout << "Equal" << endl : cout << "Not equal" << endl;
    */
}
