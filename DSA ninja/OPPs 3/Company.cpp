#include <iostream>
using namespace std;

// 1st base class
class Employee
{
public:
    // any data

    // virtual function are generally present in the base class
    // virtual funtion so that we can use run time polymorphism
    /*
    virtual void calculateSalary()
    {
        cout << "Employee calculateSalary has been called!" << endl;
    }
    */
   
    // these are called pure virtual function ?? basically forcing the child classes[hr, manager , engineer] to complete the virtual function if not than become abstract(ie child becoming abstract as well)
    virtual void calculateSalary() = 0;
};

// child class 1
class HR : public Employee
{
public:
    // any data member

    // function to calculate HR salary
    void calculateSalary()
    {
        cout << "HR calculateSalary has been called!" << endl;
    }
};

// child 2
class Manager : public Employee
{
public:
    // any data member

    // function to calculate manager salary
    void calculateSalary()
    {
        cout << "Manager calculateSalary has been called!" << endl;
    }
};

// child 2
class Engineer : public Employee
{
public:
    // any data member

    // function to calculate manager salary
    void calculateSalary()
    {
        cout << "Engineer calculateSalary has been called!" << endl;
    }
};

int main()
{
    // Remember parent class pointer can point a child class pointer
    /*
    that's why employee pointer is pointing towards hr, manager, enginner class objects
    */

    // make an array to store salary of all employee
    Employee **e = new Employee *[9]; // 1 hr, 3 managers, 5 engineers

    for (int i = 0; i < 9; i++)
    {
        // fill employee details
        if (i == 0) // fill hr
        {
            HR head;
            e[i] = &head;
        }
        else if (i <= 3) // fill all three managers
        {
            Manager m;
            e[i] = &m;
        }
        else
        {
            Engineer eng; // fill rest of the engineers
            e[i] = &eng;
        }
    }

    // printing the employee salary data
    for (int i = 0; i < 9; i++)
    {
        e[i]->calculateSalary();
    }

    // delete the dynamic variable
    for (int i = 0; i < 9; i++)
        delete e[i];
    delete e;
}