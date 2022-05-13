#include <iostream>
using namespace std;

int countZeros(int n)
{
  if (n <= 9)
  {
    if (n == 0)
    {
      return 1;
    }
    else
    {
      return 0;
    }
  }
  int count = 0;
  if (n % 10 == 0)
  {
    count = 1;
  }
  return count + countZeros(n / 10); // here we are adding count to the recursion, where count is the calulation we.re doing and rest is done by recursion
}
// int count = 0;
// int countZeros(int n)
// {
//   if (n == 0)
//   {
//     return count;
//   }
//   if ((n % 10) == 0)
//   {
//     count++;
//   }
//   int smallz = countZeros(n / 10);
//   return count;
// }

int main()
{
  int n;
  cin >> n;
  cout << countZeros(n) << endl;
}
