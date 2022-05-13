#include <iostream>
using namespace std;
#include <cstring>
#include <cmath>

int stringToNumber(char input[])
{
  if (strlen(input) == 1) // base case
  {
    return (input[0] - '0');
  }
  int a = stringToNumber(input + 1);
  int b = input[0] - '0';
  return ((b * pow(10, strlen(input) - 1) + a)); // Imp: b is the small calculation that we're doing and a will be handled by recursion using out small calculation. 
}

int main()
{
  char input[50];
  cin >> input;
  cout << stringToNumber(input) << endl;
}
