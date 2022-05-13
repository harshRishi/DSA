#include <iostream>
using namespace std;

class Edge
{
public:
    // data members
    int v1, v2, w;

    // default construtor
    Edge()
    {
        int v1, v2, w;
    }
    // Parameterized construtor
    Edge(int v1, int v2, int w)
    {
        this->v1 = v1;
        this->v2 = v2;
        this->w = w;
    }

    // functions
    void printEdge()
    {
        if (v1 < v2)
            cout << this->v1 << " " << this->v2 << " " << this->w << endl;
        else
            cout << this->v2 << " " << this->v1 << " " << this->w << endl;
    }
};