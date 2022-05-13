#include <iostream>
#include <string.h>
using namespace std;

class student
{
public:
    int age;
    int const rollNumber; // we need to use initialization list (As it a constant data type and we're not initizing them along)
    int &x;               // we need to use initialization list (As it a refrence variable type and we're not refering them along)

    // initization list
    student(int r, int age) : rollNumber(r), age(age), x(this->age) // we can also pass multiple vvalues as well as single
    {
        // in above statement we dont need to write this keyword as it is clearly defined that outer one is the int and the inner one is the one coming with argument
    }
};