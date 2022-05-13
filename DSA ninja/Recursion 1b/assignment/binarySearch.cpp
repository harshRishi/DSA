#include <iostream>
using namespace std;

int bS(int input[], int start, int end, int element)
{
    // BASE CASE
    if (start >= end)
    {
        return -1;
    }

    int mid = (start + end) / 2; 

    if (input[mid] == element) // small calculation
    {
        return mid;
    }
    else if (input[mid] < element)
    {
        return bS(input, mid + 1, end, element); // rc
    }
    else
    {
        return bS(input, start, mid - 1, element); // rc
    }
}

int binarySearch(int input[], int size, int element)
{

    return bS(input, 0, size - 1, element);
}

int main()
{
    int input[100000], length, element, ans;
    cin >> length;
    for (int i = 0; i < length; i++)
    {
        cin >> input[i];
        ;
    }

    cin >> element;
    ans = binarySearch(input, length, element);
    cout << ans << endl;
}