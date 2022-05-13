#include <iostream>
using namespace std;

int sum(int a[], int size, int si = 0) // Here si is set as an default argument if not passed by main it will assume it's value as giving by code which can only be defined on rigth most arrgument and so on
{
  int ans = 0;
  for (int i = si; i < size; i++)
  {
    ans += a[i];
  }
  return ans;
}

int main()
{
  int a[20];
  cout << sum(a, 20) << endl;
}