#include <iostream>
using namespace std;
#include "constantFunctions.cpp"

int main() {
	Fraction f1(10, 2);
	Fraction f2(15, 4);

	Fraction const f3;

	cout << f3.getNumerator() << " " << f3.getDenominator() << endl; //  for const object we cam only call const function , normal function cannot be called

	// f3.setNumerator(10); // not allowed
}

