#include <iostream>
using namespace std;

int main()
{
  // FOR SINGLE ELEMENT DELETION FROM HEAP
  int *p = new int[];
  delete p; // here P isn't delete, int arr stored in heap is actually delete we can actully use p later.

  p = new int[];
  delete p; // again P isn't deleted heap storage new int is.

  // FOR DELETION OF AN ARRAY
  int *arr = new int[];
  delete[] p; // Using this will delete the whole arrays from the heap storage
}