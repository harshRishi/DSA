#include <iostream>
using namespace std;

// ------------ static member of a class belongs to class itself no to the object therefore can be accessed using  "className :: staticMenberName;" -----//

class Student
{
private:
    static int totalStudents; // total number of students present

public:
    int rollNumber;
    int age;

    Student() // whenever we make any new object with student class it will call this construtor and thus we'll update totalStudent by one
    {
        totalStudents++;
    }

    int getrollNumber()
    {
        return rollNumber;
    }

    static int getTotalStudents() // making this function static so that we can use it in main
    {
        return totalStudents;
    }
};

int Student ::totalStudents = 0; // initialization of any static property of a class can only be done outside of the class
