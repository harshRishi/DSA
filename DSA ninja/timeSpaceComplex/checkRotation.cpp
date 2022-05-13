#include <iostream>
using namespace std;

int countRotations(int arr[], int low, int high)
{
    if (high < low)
        return 0;

    // If there is only one element left
    if (high == low)
        return low;

    // Find mid
    int mid = low + (high - low) / 2; /*(low + high)/2;*/

    // Check if element (mid+1) is minimum element.
    // Consider the cases like {3, 4, 5, 1, 2}
    if (mid < high && arr[mid + 1] < arr[mid])
        return (mid + 1);

    // Check if mid itself is minimum element
    if (mid > low && arr[mid] < arr[mid - 1])
        return mid;

    // Decide whether we need to go to left half or
    // right half
    if (arr[high] > arr[mid])
        return countRotations(arr, low, mid - 1);

    return countRotations(arr, mid + 1, high);
}

int arrayRotateCheck(int *input, int size)
{
    return countRotations(input, 0, size - 1);
    //     if(size == 1 || size == 0) {
    //         return 0;
    //     }
    //     //Write your code here
    //     if(input[0] > input[1]){
    //         return 1;
    //     }

    //     int roq = arrayRotateCheck(input+1, size -1);
    //     return roq + 1;
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

        cout << arrayRotateCheck(input, size) << endl;
        delete[] input;
    }

    return 0;
}