#include <iostream>
using namespace std;

// int sum(int a[], int n) // IMPORTANT this is not the arr here it is a pointer to arr[] which is in the main function and thet's why we need to specify the size of the arr so that pointer can located the arr start and and end according to the size.
int sum(int *a, int n) // now as we know it's not an array we can write it as a pointer. altho a[] can also be written as (*a)
{
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = ans + a[i];
    }
    cout << sizeof(a) << endl;
    return ans;
}

int main()
{
    int arr[10];
    cout << sizeof(arr) << endl;
    cout << sum(arr, 10) << endl; // here we can pass a part of an array by passing the pointer which points towards to the third place of the arr
}
