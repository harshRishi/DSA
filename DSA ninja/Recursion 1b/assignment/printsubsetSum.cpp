#include <iostream>
using namespace std;

void printA(int input[], int size, int output[], int m, int k)
{
    // BASE CASE
    if (size == 0) // after recursing through whole input array
    {
        if (k == 0) // print only those subsets which after substracing with k give 0
        {
            for (int i = 0; i < m; i++)
            {
                cout << output[i] << " ";
            }
            cout << endl;
            return;
        }
        else
        {
            return;
        }
    }
    printA(input + 1, size - 1, output, m, k); // not including the first value of input array

    int temp[1000]; // making a temp array so to store the output array data which is initailly zero as size is also zero but after few recursive calls this will have some data which need sto be printed
    int i = 0;
    for (; i < m; i++)
    {
        temp[i] = output[i];
    }
    temp[i] = input[0];                                       //---- // here we just stored the first index of the input array to last index of the output array
    printA(input + 1, size - 1, temp, m + 1, k - input[0]); // Includeing the first value of the input array
}

void printSubsetSumToK(int input[], int size, int k)
{
    int output[100];
    printA(input, size, output, 0, k);
}

int main()
{
    int input[1000], length, k;
    cin >> length;
    for (int i = 0; i < length; i++)
        cin >> input[i];
    cin >> k;
    printSubsetSumToK(input, length, k);
}
