#include <iostream>
using namespace std;
#include "testClass.cpp"

int main()
{
    char name[] = "Harsh";
    student s1(20, name);
    s1.display();

    student s2(s1); // we have changed the default copy construtor to the one which deep copy name char array
    s2.name[0] = 'x';

    s1.display();
    s2.display();

    /*
    name[4] = 'g';
    student s2(21, name);
    s2.display();

    s1.display();
    */
}