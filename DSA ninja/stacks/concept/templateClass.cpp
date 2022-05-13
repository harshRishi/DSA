#include <iostream>
using namespace std;

template <typename T, typename V> // here we've decarled the template T

class Pair
{
    T x;
    V y;

public:
    void setX(T x)
    {
        this->x = x;
    }

    T getX()
    {
        return x;
    }

    void setY(V y)
    {
        this->y = y;
    }

    V getY()
    {
        return y;
    }
};