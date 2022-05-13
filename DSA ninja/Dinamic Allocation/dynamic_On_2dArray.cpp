#include <iostream>
using namespace std;

int main()
{
  int row, col;
  cout << "Enter Rows and Columns: " << endl;
  cin >> row >> col;

  // FORMATION OF 2D ARRAYS
  int **p = new int *[row]; // Here **p is pointer towards pointer arr and to make a pointer arr the syntax is int * [row]

  for (int i = 0; i < row; i++) // Here each element is pointing to array with size of col.
  {
    p[i] = new int[col]; // Writing p[4][5] means go to pointer 4 in pointer array and then go to the array and move to the 5th element
    for (int j = 0; j < col; j++)
    {
      cin >> p[i][j]; // Taking elements from the user for the col elements
    }
  }

  // DELETION OF 2D ARRAYS
  for (int i = 0; i < row; i++)
  {
    delete[] p[i]; // here we're deleting each array
  }
  delete[] p; // here we deleted the pointer array and yes this deletion must be after all col arrays are deleted
}