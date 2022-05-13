#include <iostream>
using namespace std;

int main()
{
  int i = 10;
  int j = 20;
  int const *p = &i; // here p is pointer which is pointing towards the const int
  p = &j;            // Here we can change p as it is pointing towards an integer and through this const path of this pointer we can change that int to which it is pointing
  // (*p)++; cannot do this as p is pointing towards a const integer

  int *const p2 = &i; // here p2 is a constant ponter pointing towards a int so here we cannot chnage p2 itself but can change the value where it is pointing
  (*p2)++;             // Can be done as it is pointing towards a normal integer
  // p2 = &j; cannot not do this as p2 iself is a const pointer
}