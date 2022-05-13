#include <iostream>
using namespace std;

void increment(int &n) // This is called passByRefrence. And now the memory of int n is same as that of i
{
  n++;
}

int main()
{
  int i = 10;
  int &j = i; // Here we ref. this j to use i's memory so any changes to j will be reflacted into i as well; (same place pr jane k do raste)
  increment(i);
  cout << i << endl;

  i++;
  cout << j << endl;
  j++;
  cout << i << endl;

  int k = 50;
  j = k; // As j is ref of i so k will be reflacted in i's memory location therefore it will make i =10 to i = 50;
  cout << i << endl;
}