#include <string>
class Vehicle
{
public:
	string color;

	/*
	{
		- Writing virtual infront of the normal function tell compiler to make decision while run time
		- so as we know v2 is vehicle class object but it is point to a car class objet
		- thus if don't write virtual it will print this function only
		- but writing virtual it will run function print from the car class ie the class v2 is pointing at
		- In case there is not print name function in the car class than program will use vehicle's print funtion
	}
	*/

	// virtual function are generally present in the base class
	virtual void print()
	{
		cout << "Vehicle" << endl;
	}
};
