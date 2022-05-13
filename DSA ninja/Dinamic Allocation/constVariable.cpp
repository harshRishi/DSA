#include <iostream>
using namespace std;

int main()
{
  const int i = 9;
  cout << i << endl;

  int j = 10; // Here j have the read write access so can it provide both read-only and read write to a ref
  const int  & k = j; // VERY INPORTANT: This const doen't make the storage constant it makes the path constant to that storage as we can see below we can change j through j but cannot do it with k

  cout << k << endl;
  j++;
  cout << k << endl;

  int const j2 = 20;
  // int & k2 = j2; // here This j2 doesnt have access to Read and Write so can provied this access to a ref
  cout << j2 << endl;

}