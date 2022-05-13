#include <iostream>
#include <algorithm>
using namespace std;

int tripletSum(int *arr, int n, int num)
{
    // sort(arr, arr + n, greater<int>()); reverse Sorted
    //Write your code here
    sort(arr, arr + n);
    int l, r, count = 0;
    for (int i = 0; i < n - 2; i++)
    {

        l = i + 1;
        r = n - 1;

        while (l < r)
        {
            if (arr[i] + arr[l] + arr[r] == num)
            {
                if (arr[l] == arr[r])
                {
                    count += ((r - l + 1) * (r - l)) / 2;
                    break;
                }
                else
                {
                    int lCount = 1;
                    int rCount = 1;
                    l++;
                    r--;
                    while(arr[l] == arr[l-1]){
                        lCount++;
                        l++;
                    }
                    while(arr[r] == arr[r+1]){
                        rCount++;
                        r--;
                    }
                    count += lCount*rCount;
                }
            }
            else if (arr[i] + arr[l] + arr[r] < num)
            {
                l++;
            }
            else
            {
                r--;
            }
        }
    }
    return count;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
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

        cout << tripletSum(input, size, x) << endl;

        delete[] input;
    }

    return 0;
}