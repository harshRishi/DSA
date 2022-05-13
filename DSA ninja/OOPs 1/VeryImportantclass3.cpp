#include <iostream>
#include <algorithm>
using namespace std;

class fraction
{
private:
    int numerator;
    int denominator;

public:
    fraction(int numerator, int denominator)
    {
        this->numerator = numerator;
        this->denominator = denominator;
    }

    void print()
    {
        cout << this->numerator << "/" << denominator << endl; // here altho it's optional to write this keyword as print function does not have any similar argument
    }

    void simplify() // will not going to take any argument as througth "this" we'll get in what we need to alter
    {
        int gcd = 1; // let greatest common divisor be 1;
        int mini = min(this->numerator, this->denominator);
        for (int i = 1; i < mini; i++) // calculating gcd
        {
            if (this->numerator % i == 0 && this->denominator % i == 0)
            {
                gcd = i; // from here we'll going to get gcd
            }
        }
        this->numerator = this->numerator / gcd;
        this->denominator = this->denominator / gcd; // here also writing "this" is completely optional
    }

    // below we use refrence to avoid copying f2 but also we used const so that no one can make changes in f2 in the main function from here.
    void add(fraction const &f2) // VERY IMPORTANT we ignore this keyword through out the code coz in add function argument there is no matching word as that of numerator and denominator
    {
        int lcm = this->denominator * f2.denominator;
        int x = lcm / this->denominator;
        int y = lcm / f2.denominator;

        int num = ((x * this->numerator) + (y * f2.numerator));

        this->numerator = num;
        denominator = lcm; // as we have ignored here

        // Now we have to simplify the final f1 which is addition of f1 and f2;
        // this->simplify(); // optional
        simplify(); //----VERY IMPORTANT-------// 'this' is automatically interperted as it is comming along with add funtion
    }

    void multiply(fraction const &f2)
    {
        int deno = denominator * f2.denominator;
        int num = numerator * f2.numerator;

        numerator = num;
        denominator = deno;

        simplify();
    }
};