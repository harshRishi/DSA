#include <iostream>
using namespace std;
// #define PI 3.14

int a; // here a is global variable
void g()
{
  a++;
  cout << a << endl;
}

void f()
{
  a++;
  cout << a << endl;
  g();
}

int main()
{
  // int r;
  // cin >> r;

  // cout << PI * r * r << endl;
  a = 10;
  f();
  cout << a << endl;
}