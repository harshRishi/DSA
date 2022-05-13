#include <iostream>
using namespace std;
#include <cstring>

void helperX(char input[], int start)
{
  if (input[start] == 0)
  {
    return;
  }

  helperX(input, start + 1);

  if (input[start] == 'x')
  {
    for (int i = start; i <= strlen(input); i++)
    {
      input[i] = input[i + 1];
    }
  }
}

void removeX(char input[])
{
  helperX(input, 0);
}

int main()
{
  char input[100];
  cin.getline(input, 100);
  removeX(input);
  cout << input << endl;
}
