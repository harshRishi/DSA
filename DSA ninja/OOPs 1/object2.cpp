#include <iostream>
using namespace std;
#include "class.cpp"

int main()
{
    student s1;

    s1.setAge(23);
    s1.display();

    student *s2 = new student;

    s2->setAge(24);
    // (*s2).display();
    s2->display();
}