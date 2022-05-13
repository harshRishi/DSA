#include <iostream>
using namespace std;
#include "DynamicClass.cpp"

int main()
{
    DynamicArray d1;

    d1.addElement(10);
    d1.addElement(20);
    d1.addElement(30);
    d1.addElement(40);
    d1.addElement(50);
    d1.addElement(60);

    d1.print();

    DynamicArray d2(d1); // calling copy construtor.

    DynamicArray d3; // Calling copy asignment operator.
    d3 = d1;

    d1.addAtIndex(0, 100);

    d2.print();
    d1.print();
    d3.print();
}