#include <iostream>
using namespace std;
#include <cstring>

void removeX(char input[])
{
  if (input[0] == '\0')
  {
    return;
  }
  if (input[0] != 'x')
  {
    removeX(input + 1);
  }
  else
  {
    int i = 1;
    for (; input[i] != '\0'; i++)
    {
      input[i - 1] = input[i];
    }
    input[i - 1] = input[i];
    removeX(input);
  }
}

// hxaxrxsxh
//////////////////////-------METHOD ----/////////////
// void helper(char input[], int start)
// {
//   if (input[start] == 0)
//   {
//     return;
//   }
//   helper(input, start + 1);
//   if (input[start] == 'x')
//   {
//     for (int i = start; i <= strlen(input); i++)
//     {
//       input[i] = input[i + 1];
//     }
//   }
// }

// void removeX(char input[])
// {
//   helper(input, 0);
// }

int main()
{
  char input[100];
  cin.getline(input, 100);
  removeX(input);
  cout << input << endl;
}
