#include <iostream>
using namespace std;

bool helper(int *arr, int n, int start, int lsum, int rsum)
{

    // If reached the end
    if (start == n)
        return lsum == rsum;

    // If divisible by 5 then add to the left sum
    if (arr[start] % 5 == 0)
        lsum += arr[start];

    // If divisible by 3 but not by 5
    // then add to the right sum
    else if (arr[start] % 3 == 0)
        rsum += arr[start];

    // Else it can be added to any of the sub-arrays
    else

        // Try adding in both the sub-arrays (one by one)
        // and check whether the condition satisfies
        return helper(arr, n, start + 1, lsum + arr[start], rsum) || helper(arr, n, start + 1, lsum, rsum + arr[start]);

    // For cases when element is multiple of 3 or 5.
    return helper(arr, n, start + 1, lsum, rsum);
}

// Function to start the recursive calls
bool splitArray(int *input, int size)
{
    // Initially start, lsum and rsum will all be 0
    return helper(input, size, 0, 0, 0);
}

int main()
{

    int size;
    cin >> size;
    int *input = new int[1 + size];

    for (int i = 0; i < size; i++)
        cin >> input[i];

    if (splitArray(input, size))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }

    return 0;
}
