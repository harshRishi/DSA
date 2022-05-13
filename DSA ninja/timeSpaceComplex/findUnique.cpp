#include <iostream>
using namespace std;

int findUnique(int *arr, int n)
{
    // Write your code here

    if (n == 0)
    { //base case
        return arr[0];
    }

    return (arr[0] ^ (findUnique(arr + 1, n - 1))); // used XOR associative property which substracts bitwise (i.e binary) 
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

        cout << findUnique(input, size) << endl;
    }

    return 0;
}