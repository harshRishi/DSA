#include <iostream>
#include <string.h>
using namespace std;

class student
{
private:
    int age;

public:
    char *name;
    student(int age, char *name)
    {
        this->age = age;
        // shallow copy
        // this->name = name; this will copy only the 0th location the array

        //Deep copy, this will copy the whole array to new location which is only accesable through that perticular student
        this->name = new char[strlen(name) + 1]; // +1 is for the null char at the end of the char array of the perticular student
        strcpy(this->name, name);                // strcyp is string copy function which copy ths string content
    }

    void display()
    {
        cout << name << " " << age << endl;
    }

    //-------------------VERY IMPORTANT CONCEPT----------/////
    // Copy construtor [after creating this copy const, default one will be vanished autom]
    student(student const &s) // that's why here we can not use 'student s' coz this will call copy const which is not here now and thus we need pass this by refrence
    {
        this->age = s.age;
        // this->name = s.name; // this is default copy construtor and THEREFOR WILL MAKE A SHALLOW COPY

        //Deep Copy
        this->name = new char[strlen(s.name) + 1];
        strcpy(this->name, s.name);
    }
};