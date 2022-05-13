#include <iostream>
using namespace std;

int lastIndex(int input[], int size, int x)
{
  if (size == 0)
  {
    return -1;
  }

  int ans = lastIndex(input + 1, size - 1, x); //recursive call

  if(ans != -1) { // small calculation
    return ans + 1;
  }

  if (input[0] == x) // if ans is still one then check weather first index of the array is x or not if no than return ans as -1 otherwise return ans + 1;
  {
    return ans + 1;
  }
  else
  {
    return ans;
  }
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

  cout << lastIndex(input, n, x) << endl;
}
