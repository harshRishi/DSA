
#include <iostream>
using namespace std;

int findDuplicate(int *arr, int n)
{
    //Write your code here
    int sumN = ((n - 2) * (n - 1)) / 2; // sum of first n - 2 natural number
    int sumA = 0;

    for (int i = 0; i < n; i++)
    { // sum of the array
        sumA += arr[i];
    }
    return sumA - sumN; // should return the duplicate value
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

        for (int i = 0; i < size; i++)
        {
            cin >> input[i];
        }

        cout << findDuplicate(input, size) << endl;
    }

    return 0;
}

/////// -------------------method 2 -------------/////////

// #include <cmath>
// int findDuplicate(int *a, int n)
// {
//     if (n == 2)
//     {
//         if (a[0] == a[1])
//             return a[0];
//     }

//     for (int i = 0; i < n; i++)
//     {
//         int index = abs(a[i]);

//         a[index] = -a[index];

//         if (a[index] > 0)
//             return abs(a[i]);
//     }
// }