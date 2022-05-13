#include <iostream>
using namespace std;

void merge(int a[], int si, int ei)
{
    // BASE CASE
    if (si >= ei)
    {
        return;
    }
    int mid = ((si + ei) / 2); // breaking the input[] into 2 halfs

    merge(a, si, mid);     // for 1st half
    merge(a, mid + 1, ei); // for 2nd half

    int s = ei - si + 1; // size of the finally mergedArr
    int *mergeArr = new int[s];

    int i = si;
    int j = mid + 1;
    int fillerIndex = 0;         // Making our mergeArr with this starting index
    for (; i <= mid && j <= ei;) // dividing the a[] into two equal halfs
    {
        (a[i] > a[j]) ? mergeArr[fillerIndex++] = a[j++] : mergeArr[fillerIndex++] = a[i++]; // Ternary
    }

    // IF their are more elements left in rigth part of the input[] basically j th part
    for (; i <= mid; i++)
    {
        mergeArr[fillerIndex++] = a[i];
    }
    for (; j <= ei; j++)
    {
        mergeArr[fillerIndex++] = a[j];
    }
    //if their are more elements left in the left part of the input[] basically i th part

    //      NOW we'll copy this mergeArr to our main input[];
    int p = 0, k = si;
    for (p = 0; p < s; p++) // here s is the size of the mergeArr
    {
        a[k] = mergeArr[p];
        k++;
    }
    // Delete merge arr from the heap
    delete[] mergeArr;
}

void mergeSort(int input[], int size)
{
    // Edge CASE
    if (size == 0 || size == 1)
    {
        return;
    }
    int start = 0, end = size - 1;
    merge(input, start, end);
}

int main()
{
    int length;
    cin >> length;
    int *input = new int[length];
    for (int i = 0; i < length; i++)
        cin >> input[i];
    mergeSort(input, length);
    for (int i = 0; i < length; i++)
    {
        cout << input[i] << " ";
    }
    delete[] input;
    return 0;
}