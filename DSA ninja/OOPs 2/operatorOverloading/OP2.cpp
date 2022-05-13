// see OOPs 2 lecture Operator Overlaoding 2

#include <iostream>
using namespace std;

class Fraction
{
private:
    int numerator;
    int denominator;

public:
    Fraction(int numerator, int denominator)
    {
        this->numerator = numerator;
        this->denominator = denominator;
    }

    void print()
    {
        cout << this->numerator << " / " << denominator << endl;
    }

    void simplify()
    {
        int gcd = 1;
        int j = min(this->numerator, this->denominator);
        for (int i = 1; i <= j; i++)
        {
            if (this->numerator % i == 0 && this->denominator % i == 0)
            {
                gcd = i;
            }
        }
        this->numerator = this->numerator / gcd;
        this->denominator = this->denominator / gcd;
    }

    Fraction add(Fraction const &f2)
    {
        int lcm = denominator * f2.denominator;
        int x = lcm / denominator;
        int y = lcm / f2.denominator;

        int num = x * numerator + (y * f2.numerator);

        Fraction fNew(num, lcm);
        fNew.simplify(); // making fnew simplify as if we do not write  fnew. then simplify will run on 'this' which in this case is f1
        return fNew;
    }

    void multiply(Fraction const &f2)
    {
        numerator = numerator * f2.numerator;
        denominator = denominator * f2.denominator;

        simplify();
    }
    // -------------------------------  OPERATOR OVERDLING------------------------------//
    /* all function below are Constant function as they are not changing anything in "this" they are just using there properties */

    Fraction operator+(Fraction const &f2) const // OPERATOR OVERLOADIND
    {
        int lcm = this->denominator * f2.denominator;
        int x = lcm / denominator;
        int y = lcm / f2.denominator;

        int num = x * numerator + (y * f2.numerator);

        Fraction fNew(num, lcm);
        fNew.simplify(); // making fnew simplify as if we do not write  fnew. then simplify will run on 'this' which in this case is f1
        return fNew;
    }

    Fraction operator*(Fraction const &f2) const // OPERATOR OVERLOADIND
    {
        int num = numerator * f2.numerator;
        int deno = denominator * f2.denominator;

        Fraction fNew(num, deno);
        fNew.simplify();
        return fNew;
    }

    bool operator==(Fraction const &f2) const // OPERATOR OVERLOADIND
    {
        return (this->numerator == f2.numerator && this->denominator == f2.denominator); // if exp is true return ture othwise false
    }

    // Pre-Increment operator
    Fraction &operator++() // here we've passed the return object by refrence so that the system created buffer is actually pointing towards the same memorty as that of 'this'
    {
        numerator = numerator + denominator;
        this->simplify();
        return (*this); // -------- Very Important ---------// as 'this' is a pointer it will return the memory location of the this so to return the content of this i.e f1 we need to mark *this which will return the whole content of f1
    }
};
