#include <iostream>
using namespace std;

void pA(int input[], int size, int output[], int m)
{
    // BASE BASE
    if (size == 0)
    {
        for (int i = 0; i < m; i++)
        {
            cout << output[i] << " "; // print the whole row with gaps
        }
        cout << endl; // than endl
        return;
    }
    // when we did not included the 1st index val with our subset
    pA(input + 1, size - 1, output, m);

    int temp[1000];
    int i = 0;
    for (; i < m; i++)
    {
        temp[i] = output[i];
    }
    temp[i] = input[0]; // pasting the 0th position of input arry at the end of the temp arr after copy data from the output arr

    // When we did included the 1st index val with out subset which is been printed
    pA(input + 1, size - 1, temp, m + 1);
}
void printSubsetsOfArray(int input[], int size)
{
    int output[100];
    pA(input, size, output, 0);
}

int main()
{
    int input[1000], length;
    cin >> length;
    for (int i = 0; i < length; i++)
        cin >> input[i];
    printSubsetsOfArray(input, length);
}
