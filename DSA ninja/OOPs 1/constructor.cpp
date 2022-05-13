#include <iostream>
using namespace std;
#include "class.cpp"

int main()
{

   /* student s1; // Constructor is called every time we make student oriented object
    s1.display();

    student s2;

    student *s3 = new student;
    s3->display();

    cout << "Parameterized Construtor called!" << endl;
    // student s4; // this will call the default construtor to call parameter consturtor we need to pass argument in it
    student s4(10);
    s4.display(); // now this will make s2 roll number to be 10; as argument is passed as 10;

    student s5(24, 178588);
    s5.display(); */

    student s6(10, 101);
    cout << "Address of s6: " << &s6 << endl;
    s6.display();

    student s7(10);
    s7.display();

}