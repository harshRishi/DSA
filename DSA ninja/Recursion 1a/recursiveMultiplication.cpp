#include <iostream>
using namespace std;

int multiplyNumbers(int x, int y)
{
  if (x < y) // To reduce recursion calls
  {
    multiplyNumbers(y, x);
  }
  if (y != 0 && x != 0) // recurse only if y and x are not equal to zero
  {
    return (x + multiplyNumbers(x, y - 1)); // X + X + X + X ... y times
  }
  else
  {
    return 0;
  }
}

int main()
{
  int m, n;
  cin >> m >> n;
  cout << multiplyNumbers(m, n) << endl;
}
