#include <iostream>
using namespace std;

void reverse(int input[], int si, int ei)
{
    // BASE CASE
    if (si >= ei)
    {
        return;
    }

    reverse(input, si + 1, ei - 1); // RC

    // Swap the first and last element of the array
    int t = input[si];
    input[si] = input[ei];
    input[ei] = t;
}

void rotate(int *input, int d, int n)
{
    //Write your code here
    reverse(input, 0, n - 1);     // reversing the whole array
    reverse(input, 0, n - 1 - d); // reversing till n-d element
    reverse(input, n - d, n - 1); // reversing last d elements
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int size;
        cin >> size;

        int *input = new int[size];

        for (int i = 0; i < size; ++i)
        {
            cin >> input[i];
        }

        int d;
        cin >> d;

        rotate(input, d, size);

        for (int i = 0; i < size; ++i)
        {
            cout << input[i] << " ";
        }

        delete[] input;
        cout << endl;
    }

    return 0;
}