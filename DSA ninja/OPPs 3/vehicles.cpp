#include <iostream>
#include <string>
using namespace std;

class vehicle
{
    // data members
private:
    int maxSpeed;

protected:
    int numTyres;

public:
    string color;

    // construtors
    vehicle()
    {
        cout << "vehicle's default construtor called" << endl;
    }

    vehicle(int a)
    {
        cout << "vehicle's parameterized construtor called" << endl;
    }
};