#include <iostream>  // You need to dry to get the base case and do watch the hint video which is recursion part b assignment
using namespace std;

int subsetSumToK(int input[], int n, int output[][50], int k)
{
    // Write your code here
    //first of all base case need to be set
    //if  we have traversed the whole input arr and
    if (n == 0)
    {
        if (k == 0)
        { //we find that our sum is 0 then we mark ouput[0][0] = 0
            output[0][0] = 0;
            return 1; //and return the size or output which is 1
        }
        else
        {
            return 0; //else we return 0
        }
    }

    int o1[1000][50], o2[1000][50];                //make two result arrays
    int x = subsetSumToK(input + 1, n - 1, o1, k); //this will return the size of the result arr when we do not consider the first element

    int y = subsetSumToK(input + 1, n - 1, o2, k - input[0]);
    //this will return size of result arr when we do consider the first element
    //because for a subset i have two choices
    //either I can choose the curr element of leave it right

    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j <= 50; j++)
            output[i][j] = o1[i][j];
    }
    for (int i = 0; i < y; i++)
    {
        int number_of_columns = o2[i][0];
        output[i + x][0] = 1 + number_of_columns;
        output[i + x][1] = input[0];
        for (int j = 1; j <= number_of_columns; j++)
            output[i + x][j + 1] = o2[i][j];
    }

    return x + y;
}

int main()
{
    int input[20], length, output[10000][50], k;
    cin >> length;
    for (int i = 0; i < length; i++)
        cin >> input[i];

    cin >> k;

    int size = subsetSumToK(input, length, output, k);

    for (int i = 0; i < size; i++)
    {
        for (int j = 1; j <= output[i][0]; j++)
        {
            cout << output[i][j] << " ";
        }
        cout << endl;
    }
}