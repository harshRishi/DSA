#include <iostream>
using namespace std;

class ComplexNumbers
{
private:
    int real;
    int imaginary;

public:
    void print()
    {
        cout << real << " + "
             << "i" << imaginary << endl;
    }

    ComplexNumbers(int real, int imaginary)
    {
        this->real = real;
        this->imaginary = imaginary;
    }

    void plus(ComplexNumbers const &Cn)
    {
        real = this->real + Cn.real;
        imaginary = this->imaginary + Cn.imaginary;
    }

    void multiply(ComplexNumbers const &Cn)
    {
        int x = real; // before we change real we need to store that real into a int variable so that we can use that in the imaginary part
        real = (this->real * (Cn.real)) - (this->imaginary * (Cn.imaginary));
        imaginary = (x * Cn.imaginary) + (Cn.real * imaginary);
    }
};