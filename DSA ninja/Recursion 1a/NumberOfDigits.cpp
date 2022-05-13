#include <iostream>
using namespace std;
int counter = 0;

int count(int n)
{
  if (n == 0)
  {
    return 0;
  }
  int returns = count(n / 10);
  return returns + 1;
}

int main()
{
  int n;
  cin >> n;

  cout << count(n) << endl;
}