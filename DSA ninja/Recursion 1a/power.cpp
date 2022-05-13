#include <iostream>
using namespace std;

int power(int x, int n)
{
  if (n == 0)
  {
    return 1;
  }
  int returns =  power(x, n - 1);
  return x * returns;
}

int main()
{
  int x, n;
  cin >> x >> n;

  cout << power(x, n) << endl;
}
