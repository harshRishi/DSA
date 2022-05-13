#include <iostream>
using namespace std;

class student
{
public:
    student()
    {
        cout << "Construtor Called!" << endl;
    }

    int age;
    int rollNumber;

    student(int rollNumber)
    {
        cout << "Construtor 2 Called!" << endl;
        (*this).rollNumber = rollNumber;
    }

    student(int age, int rollNumber)
    {
        cout << "Construtor 3 Called!" << endl;
        this->age = age;
        (*this).rollNumber = rollNumber;
    }

    void display()
    {
        cout << age << " " << rollNumber << endl;
    }

// private: this destrutor can not be called in the private scope
    ~student() // destrutor called (it is called automatically)
    {
        cout << "Destrutor called !" << endl;
    }
};