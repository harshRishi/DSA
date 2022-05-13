#include <iostream>
#include <algorithm>
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
    for (p = 0; p < s; p++)
    {
        a[k] = mergeArr[p];
        k++;
    }
    // Delete merge arr from the heap
    delete[] mergeArr;
}

void mergeSort(int input[], int size)
{
    // BASE CASE
    if (size == 0 || size == 1)
    {
        return;
    }
    int start = 0, end = size - 1;
    merge(input, start, end);
}

void intersection(int *arr1, int *arr2, int n, int m)
{
    mergeSort(arr1, n);
    mergeSort(arr2, m);

    int i = 0, j = 0;
    for (; i < n && j < m;)
    {
        if (arr1[i] == arr2[j])
        {
            cout << arr1[i++] << " ";
            j++;
        }
        else if (arr1[i] > arr2[j])
        {
            j++;
        }
        else
        {
            i++;
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int size1, size2;

        cin >> size1;
        int *input1 = new int[size1];

        for (int i = 0; i < size1; i++)
        {
            cin >> input1[i];
        }

        cin >> size2;
        int *input2 = new int[size2];

        for (int i = 0; i < size2; i++)
        {
            cin >> input2[i];
        }

        intersection(input1, input2, size1, size2);

        delete[] input1;
        delete[] input2;

        cout << endl;
    }

    return 0;
}