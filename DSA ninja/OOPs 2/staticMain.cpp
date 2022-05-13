#include <iostream>
using namespace std;
#include "staticClass.cpp"

int main()
{
    Student s1;
    Student s2;
    Student s3, s4, s5;

    cout << s1.rollNumber << " " << s1.age << endl;
    cout << "Total Students: " << Student :: getTotalStudents() << endl;
}
