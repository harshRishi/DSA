#include <iostream>
using namespace std;

int subs(string input, string output[])
{
    //Base Case
    if (input.empty())
    {
        output[0] = "";
        return 1;
    }

    string smallString = input.substr(1); // making string smaller for recursive use
    // Recursive Call
    int smallOutputSize = subs(smallString, output);

    for (int i = 0; i < smallOutputSize; i++) // here we adding the further subsequences to the output sting of array
    {
        output[i + smallOutputSize] = output[i] + input[0]; // as Output and input are strings we can add both of them directly
    }

    return 2 * smallOutputSize; // as smalloutput will give half after removing the first char from the string
}

int main()
{
    string input;
    cin >> input;

    int n = input.size(); // will be used to calculate the size of the output string array

    int outputSize = 1;
    for (int i = 0; i <= n; i++) // 
    {
        outputSize *= 2;
    }

    string *output = new string[outputSize];

    int count = subs(input, output);

    for (int i = 0; i < count; i++)
    {
        cout << output[i] << endl;
    }
}