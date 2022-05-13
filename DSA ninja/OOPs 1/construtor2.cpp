#include <iostream>
#include "class2.cpp"
using namespace std;

int main()
{
    // static
    student s1;
    cout << "S1 :  ";
    s1.display();

    student s2(s1); // using copy construtor statically
    cout << "S2 :  ";
    s2.display();

    student s5;
    cout << "S5 :  ";
    s5.display();

    s5 = s1; // copy assignment oprator
    s5.display();

    // DYNAMICALLY
    student *s3 = new student;
    cout << "S3 : ";
    s3->display();

    student *s4 = new student(*s3); // using copy construtor dynamically
    cout << "S4 : ";
    s4->display();

    student *s6 = new student;
    cout << "S6 : ";
    s6->display();

    (*s6) = (*s3); // copy assignment operator
    s6->display();

    delete s3;
    delete s4;
    delete s6;
}