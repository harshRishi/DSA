#include <iostream>
using namespace std;
#include "VeryImportantclass3.cpp"

int main()
{
    fraction f1(10, 2);
    fraction f2(15, 4);
    f1.add(f2); // callind add function from class fraction

    f1.print(); // f1 after addition

    f1.multiply(f2);
    f1.print();
}