#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v; // created a vector statically
    // vector<int> *vDynamicAllocation = vector<int>();  // created a vector dynamically

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);

    v[1] = 100;

    cout << v[0] << endl; // using v.[] will give you any data inspite of the vector size so can also give you garbage. instead use v.at() function
    cout << v[1] << endl;
    cout << v[2] << endl;
    cout << v[3] << endl;

    cout << v.size() << endl; // this function will give vector size
    cout << v.capacity() << endl;

    cout << v.at(2) << endl; // this function will give index data from the vector v
    cout << v.at(6) << endl;
}