#include <iostream>
using namespace std;
#include <vector>

// there should not be any perticular order as it is an UnorderedMap

int main()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);

    // making iterator on vector
    vector<int>::iterator vI = v.begin();

    for (; vI != v.end(); vI++)
    {
        cout << *vI << endl; // iterator vI is a pointer so to print value of what it is pointing we need use *vI
    }
}