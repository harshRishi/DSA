#include <iostream>
#include <algorithm>
using namespace std;

int partition(int input[], int si, int ei)
{
    int pivot = input[ei]; // Initial position of pivot
    int pi = si;

    for (int i = si; i < ei; i++)
    {
        if (input[i] < pivot)
        {
            int t = input[pi];
            input[pi] = input[i];
            input[i] = t;
            pi++;
        }
    }
    int temp = input[pi];
    input[pi] = input[ei];
    input[ei] = temp;

    return pi;
}

void quickSort(int input[], int start, int end) 
{
    if (start >= end)
    {
        return;
    }
    int pi = partition(input, start, end);
    quickSort(input, start, pi - 1);
    quickSort(input, pi + 1, end);
}

////////////////    SORTING WITH QUICK //////////////// we can also use -- sort(array, to where the array needs to be sorted); as we're using #include<algorithm>

int pairSum(int *arr, int n, int num)
{
    //Write your code here
    quickSort(arr, 0, n - 1);

    int i = 0, j = n - 1, count = 0;
    if (arr[i] == arr[j] && arr[i] + arr[j] == num) // as array is sorted we can say if first nd last digit are same that means all digits are same and we can return 
    {
        return (n * (n - 1)) / 2;
    }
    for (; i < j;)
    {
        if ((arr[i] + arr[j]) == num)
        {
            int x = 1;
            while (i < n && arr[i] == arr[i + 1] && arr[i] != arr[j])
            {
                x++;
                i++;
            }
            int y = 1;
            while (j >= 0 && arr[j - 1] == arr[j] && arr[i] != arr[j])
            {
                y++;
                j--;
            }

            count += x * y;
            i++;
            j--;
        }
        else if ((arr[i] + arr[j]) > num)
        {
            j--;
        }
        else
        {
            i++;
        }
    }
    return count;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int size;
        int x;

        cin >> size;
        int *input = new int[size];

        for (int i = 0; i < size; i++)
        {
            cin >> input[i];
        }

        cin >> x;

        cout << pairSum(input, size, x) << endl;

        delete[] input;
    }

    return 0;
}