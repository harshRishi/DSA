#include <iostream>
using namespace std;

int subset(int input[], int n, int output[][20])
{
    //BASE CASE
    if (n <= 0)
    {
        output[0][0] = 0;
        return 1;
    }
    int smallOutput = subset(input + 1, n - 1, output);
    for (int i = 0; i < smallOutput; i++)
    {
        int col = output[i][0] + 1;
        output[i + smallOutput][0] = col;          // adding one to each row with col 0
        output[smallOutput + i][1] = input[0]; // adding input[0] in each row of col 1;
        for (int j = 2; j < col + 1; j++) // copying all output element to the small problem
        {
            output[smallOutput + i][j] = output[i][j - 1];
        }
    }
    return 2*smallOutput; // return 2 * output bcoz output size will be half of the size of the original array
}

int main()
{
    int input[20], length, output[35000][20];
    cin >> length;
    for (int i = 0; i < length; i++)
        cin >> input[i];

    int size = subset(input, length, output);

    for (int i = 0; i < size; i++)
    {
        for (int j = 1; j <= output[i][0]; j++)
        {
            cout << output[i][j] << " ";
        }
        cout << endl;
    }
}
