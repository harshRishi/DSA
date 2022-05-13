#include <iostream>
using namespace std;

int allIndexes(int input[], int size, int x, int output[])
{
  if (size == 0) // base case
  {
    return 0;
  }
  int smallAns = allIndexes(input, size - 1, x, output); // recursive call
  if (input[size - 1] == x) // Small Calculation
  {
    output[smallAns] = size - 1;
    smallAns++;
  }
  return smallAns; // returning size of the output array to main
}

int main()
{
  int n;
  cin >> n;

  int *input = new int[n];

  for (int i = 0; i < n; i++)
  {
    cin >> input[i];
  }

  int x;

  cin >> x;

  int *output = new int[n];

  int size = allIndexes(input, n, x, output);
  for (int i = 0; i < size; i++) // print output
  {
    cout << output[i] << " ";
  }

  delete[] input;

  delete[] output;
}
