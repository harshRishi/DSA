#include <iostream>
#include <cstring>
using namespace std;

void helpreplacePi(char input[], int start)
{
  // check weather giving string is of length one.
  if (input[start] == 0 || input[start + 1] == '\0')
  {
    return;
  }
  // Recursive Call
  helpreplacePi(input, start + 1);

  // shifting array from end by 2 positions so that 14 can be stored
  if (input[start] == 'p' && input[start + 1] == 'i')
  {
    for (int i = strlen(input); i >= start + 2; i--)
    {
      input[i + 2] = input[i];
    }

    // Putting 3.14 in place of 0, 1, 2, 3 position over shifted input string
    input[start] = '3';
    input[start + 1] = '.';
    input[start + 2] = '1';
    input[start + 3] = '4';
  }
}

void replacePi(char input[])
{
  helpreplacePi(input, 0);
}

int main()
{
  char input[10000];
  cin.getline(input, 10000);
  replacePi(input);
  cout << input << endl;
}
