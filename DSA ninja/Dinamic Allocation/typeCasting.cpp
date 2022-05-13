#include <iostream>
using namespace std;

int main()
{
  int i = 65;
  char c = i; // This is called implicit typeCasting. basically one date type to be passed inside other
  cout << c << endl;

  int *p = &i; 
  char *pc = (char *)p; // this is called explicit typeCasting. telling compiler to treat this as an char not as an interger
  cout << *p << endl;
  cout << * pc << endl;

  cout << p << endl;
  cout << pc << endl; // here in Char type pointer, it will print the the value till encounter the null char which is actually place just next to 65ss

  // float *pf = &i;

  // cout << "Float: " << *pf;
  // cout << "char: " << *pc;
  // cout << "Int: " << *p;
}