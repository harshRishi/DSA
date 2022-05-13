#include <iostream>
using namespace std;
#include "Student.cpp"
#include "Teacher.cpp"
#include "TA_multiple_inheritance.cpp"

int main()
{
	// construtor call will be according to the class we have wrote first in TA_multiple_inheritance. ie Teacher and than student
	TA a;

	/*
	as 'a' has multiple base classes so we need to defined which print we need to call for that we
	have write the class of which we want to use the print function while using scope Resolution operator ::
	*/
	//	a.Student :: print();

	a.print();

	// in Case property ins't available in the class itself // syntax object.Class_name :: propertyName = "upadate"
	a.Teacher ::name = "abcd";
}
