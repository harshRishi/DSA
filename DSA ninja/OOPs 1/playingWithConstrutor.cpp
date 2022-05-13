#include <iostream>
using namespace std;
#include "class2.cpp"

int main()
{
    student s1; // construtor will be called

    student s2(101); // const 2 will be called

    student s3(24, 101); // const  3 will be called.

    student s4(s3); // copy construtor will be called

    // will be interperted as student s5(s4);
    student s5 = s4; // In this case compiler knows s5 is not yet created that's why it uses Copy Construtor instead of first creating s5 and than using copy assignment oprator therefor no default const will be called
}