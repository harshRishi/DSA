#include <unordered_map>
void printIntersection(int arr1[], int arr2[], int n, int m)
{
    // Write your code here
    unordered_map<int, int> checkIntersection;
    for (int i = 0; i < n; i++)
    {
        checkIntersection[arr1[i]]++; // if key is there increse the freq and if it is there the store default 0 and increase it by one
    }

    for (int i = 0; i < m; i++)
    {
        if (checkIntersection[arr2[i]] > 0)
        {
            cout << arr2[i] << endl;
            checkIntersection[arr2[i]]--;
        }
    }
}