#include <iostream>
using namespace std;

class student
{
private:
    int age;

public:
    //Default Constructor
    student()
    {
        cout << "Construtor has been called!" << endl;
    }

    int rollNumber;

    student(int rollNumber) // AS soon as we make another construtor our default one vanishes so to make it work we need to make default by ourself
    {
        cout << "Construtor 2 called: " << endl;
        this->rollNumber = rollNumber;
    }

    student(int a, int r)
    {
        cout << "Construtor 3 Called: " << endl;
        cout << "This here represent: " << this << endl; // keyword this will print the address of the currernt object which called perticular construtor from main()
        (*this).age = a;                                 // as this keyword is a pointer variable so we need to use such syntax or use "this->age"
        this->rollNumber = r;                            // can also write like ths
    }

public:
    void display()
    {
        cout << age << " " << rollNumber << endl;
    }

    int setAge(int age)
    {
        this->age = age;
    }
};