#include <iostream>
using namespace std;

// This inline is good for only small code or function for large function it will copy that large junk to wherever the function is called
inline int max(int a, int b) // inline function:- this will copy this return statement in all the places where we're this max function is called
{
  return (a > b) ? a : b;
}

int main()
{
  int a, b;
  cin >> a >> b;

  int c = max(a, b);
  cout << c;
  // (a > b) ? cout << a : cout << b; // turnery oprator
}