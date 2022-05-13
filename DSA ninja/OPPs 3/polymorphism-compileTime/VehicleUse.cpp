#include <iostream>
using namespace std;
#include "Vehicle.cpp"
#include "Car.cpp"

int main() {
	Vehicle v;

	Car c;

	v.print();

	c.print();


	Vehicle *v1 = new Vehicle;

	Vehicle *v2;
	// v2 = &v;

	// VERY IMPORTANT - Base class pointer can point to child class 
	v2 = &c; 

	v1 -> print();

	v2 -> print();
}

