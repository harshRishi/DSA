#include <iostream>
using namespace std;
#include "templateClass.cpp"

int main() // see templates video if any doubt
{
    Pair<Pair<int, int>, int> p2; // here we've created a object with class Pair in which by using template we have passed Pair class object p4 inside p2's X
    p2.setY(30);
    Pair<int, int> p4; // created another pair class
    p4.setX(10);
    p4.setY(20);

    p2.setX(p4); // this is how we make triplet using Pair with templates

    cout << p2.getX().getX() << " " << p2.getX().getY() << " " << p2.getY() << endl;

    /*
    Pair<int, double> p1;
    p1.setX(100.34);
    p1.setY(100.34);
    cout << p1.getX() << " " << p1.getY() << endl;
    */

    /*
    Pair<int> p1; // as this pair class is made of template so before memory allocation we need to define the data we want in the place of template T(In our case)
    p1.setX(10);
    p1.setY(20);

    cout << p1.getX() << " " << p1.getY() << endl;

    Pair<double> p2;
    p2.setX(100.34);
    p2.setY(200.76);

    cout << p2.getX() << " " << p2.getY() << endl;

    Pair<char> p3;
    p3.setX("H");
    p3.setY("R");

    cout << p3.getX() << " " << p3.getY() << endl;
    */
}