#include <iostream>
#include "class.cpp"
using namespace std;

int main()
{
    // CREATING OBJESTCS STATICALLY
    student s1;
    student s2;

    student s3, s4, s5;

    s1.age = 24;
    // s1.rollNumber = 17;

    cout << s1.age << endl;
    // cout << s1.rollNumber << endl;
    s1.display();
    s2.display();

    //CREATING OBJECTS DYNAMICALLY
    student *s6 = new student;

    (*s6).age = 22;
    // (*s6).rollNumber = 16;
     (*s6).display();

    //short cut to assign any value to a dynamically created object
    s6->age = 23;
    s6->display();
    // s6 -> rollNumber = 18;
}