#include <iostream>
using namespace std;
#include "vehicles.cpp"

// inHeritance syntax
/* derived class - child class && base class -  parent class
{
    - derived_ClassName : access modifier baseClassName
}
*/

// single Inheritance
class Car : public vehicle
{
public:
    // data members
    int numGears;

    // construtors
    /*
    Car() // if we didn't wrote anything vehicle's default will be called
    {
        cout << "car's default" << endl;
    }
    */
   // recieved the interger from car class obejct and append it to our vehicle class parameterized construtor
    Car(int x) : vehicle(x) // this where we write commonds before contrutor call
    {
        cout << "car's default Called" << endl;
    }

    // functions
    void print()
    {
        cout << "Number of Tyres : " << numTyres << endl; // can we accessed as this child class inherite parent's protected and public properties
        cout << "Color : " << color << endl;
        cout << "Number of Gears : " << numGears << endl;
        // cout << "Max Speed : " << maxSpeed << endl;  we cannot access this property of parent class as this property was private and private properties can't be inherite
    }
};
