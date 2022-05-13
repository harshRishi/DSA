#include <iostream>
using namespace std;

int partition(int input[], int si, int ei)
{
    int pivot = input[ei]; // Initial position of pivot
    int pi = si;

    for (int i = si; i < ei; i++)
    {
        if (input[i] < pivot) // if the current index element is smaller than pivot than swap current element with pivot index(pi) which initally will be same i.e start position 
        {
            int t = input[pi]; 
            input[pi] = input[i];
            input[i] = t;
            pi++;
        }
    }
    int temp = input[pi]; // swaped the last index with the pivot index to move pivot to its sorted position
    input[pi] = input[ei];
    input[ei] = temp;

    return pi;
}

void doQuick(int input[], int start, int end)
{
    if (start >= end) // base case
    {
        return;
    }
    int pi = partition(input, start, end);
    doQuick(input, start, pi - 1);
    doQuick(input, pi + 1, end);
}

void quickSort(int input[], int size)
{
    doQuick(input, 0, size - 1);
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

    quickSort(input, n);
    for (int i = 0; i < n; i++)
    {
        cout << input[i] << " ";
    }

    delete[] input;
}

///////////////////-------------------using swap------------///////////////////////////

/* #include <iostream>
using namespace std;

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int input[], int start, int end)
{
    int pivot = input[end];
    int pi = start;

    for (int i = start; i < end; i++)
    {
        if (input[i] < pivot)
        {
            swap(&input[i], &input[pi]);
            pi++;
            // int temp = input[i];
            // input[i] = input[pi];
            // input[pi++] = temp;
        }
    }
    swap(&input[pi], &input[end]);
    // int temp = input[pi];
    // input[pi] = input[end];
    // input[end] = temp;

    return pi;
}

void sorting(int input[], int start, int end)
{
    if (start >= end)
    {
        return;
    }
    int pi = partition(input, start, end);
    sorting(input, start, pi - 1);
    sorting(input, pi + 1, end);
}

void quickSort(int input[], int size)
{
    sorting(input, 0, size - 1);
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

    quickSort(input, n);
    for (int i = 0; i < n; i++)
    {
        cout << input[i] << " ";
    }

    delete[] input;
} */
