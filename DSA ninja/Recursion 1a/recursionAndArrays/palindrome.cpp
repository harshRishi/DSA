#include <iostream>
using namespace std;

int length(char input[])
{
  int count = 0;
  for (int i = 0; input[i] != '\0'; i++)
  {
    count++;
  }
  return count;
}

bool helper(char input[], int start, int end)
{
  if (start >= end) // if string is having length one or zero if yes than string is already palindrome
    return true;
  if (input[start] != input[end]) // if start and end char doenst match than offcourse it's not a palindrome
    return false;
  return helper(input, ++start, --end); // call recursion by start increased  with one and end decreased by one.
}

bool checkPalindrome(char input[])
{
  int len = length(input);
  int start = 0;
  int end = len - 1;
  return helper(input, start, end);
}

int main()
{
  char input[50];
  cin >> input;

  if (checkPalindrome(input))
  {
    cout << "true" << endl;
  }
  else
  {
    cout << "false" << endl;
  }
}
