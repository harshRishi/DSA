#include <iostream>
using namespace std;
#include <cstring>

void helper(char input[], int start)
{
  if (input[start] == '\0')
  {
    return;
  }

  helper(input, start + 1);
  if (input[start] == input[start + 1])
  {
    for (int i = strlen(input); i >= start + 1; i--)
    {
      input[i + 1] = input[i];
    }
    input[start + 1] = '*';
  }
}

void pairStar(char input[])
{
  helper(input, 0);
}

int main()
{
  char input[100];
  cin.getline(input, 100);
  pairStar(input);
  cout << input << endl;
}
