#include <iostream>
using namespace std;

// we've decleared these function on top so that we can access tham while making them friend in the TRuck class other wise compiler will thorugh the error
class Bus
{
public:
    void print();
};
void test();

class Truck
{
private:
    int x;

protected:
    int y;

public:
    int z;

    // here we've decleared the whole Class Bus a friend of this Truck class
    friend class Bus;

    /* 
    // made print function of the Bus class a friend of the truck class so that it can access private and protected member of truck class
     friend void Bus :: print();

     // here we've made the normal function friend of truck class
     friend void test();
    */
};

void Bus ::print()
{
    // look here we can access the private and protected member of truck class
    Truck t;
    t.x = 10;
    t.y = 20;
    cout << t.x << " " << t.y << endl;
}

// normal function not under any class
void test()
{
    // Access truck private
    Truck t;
    t.x = 10;
    t.y = 20;
    cout << t.x << " " << t.y << endl;
}

int main()
{
    Bus b;
    b.print();

    test();
}
