#include <iostream>
using namespace std;

int main()
{
  // int *p = new int; // Stored this int in Heap storage with pointer p pointing toward the storage
  // *p = 10;
  // cout << *p << endl;

  // double * pd = new double;
  // *pd = 123.321;
  // cout << *pd << endl;

  cout << "Enter the number of element: " << endl;
  int n;
  cin >> n;

  int *arr = new int[n]; // Making an arr in heap with arr name of the pointer poiting towards first elemet of the arrays arr.

  cout << "Enter the Elements: " << endl;
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }

  int max = arr[0];
  for (int i = 1; i < n; i++)
  {
    if (arr[i] > max)
    {
      max = arr[i];
    }
  }
  cout << max << endl;
}