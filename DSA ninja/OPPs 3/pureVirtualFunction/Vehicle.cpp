class Vehicle
{
public:
	string color;

	/*
	- pure virtual function are those funtion which doesn't have any defination 
	- Such function if created in a class makes that class Asbtract class;
	- if we try to make object of such class than error occurs
	- so if derived (ie child) class completes the defination of all pure Virtual function than creating child class object won't create the error
	- completing the defination means child class should have a function name same as that of pure virtual function present in the parent class
	*/
	// Pure virtual fn
	virtual void print() = 0;
};
