#include <iostream>
#include <string.h>
using namespace std;

int ctoi(char num) // char to int
{
    int i = num - '0';
    return i;
}

char itoc(int i) // int to char
{
    char ch = 'a' + i - 1;
    return ch;
}

void helper(string input, string output)
{
    // BASE CASE
    if (input.empty())
    {
        cout << output << endl;
        return;
    }

    // RC
    char ch1 = itoc(ctoi(input[0]));
    helper(input.substr(1), output + ch1); // when we're taking only one char from the input string

    // RC
    if (input.size() > 1)
    {
        if ((ctoi(input[0]) * 10 + ctoi(input[1])) >= 10 && (ctoi(input[0]) * 10 + ctoi(input[1])) <= 26)
        {
            char ch2 = itoc(ctoi(input[0]) * 10 + ctoi(input[1]));
            helper(input.substr(2), output + ch2); // when we'er taking two char from the input string
        }
    }
}

void printAllPossibleCodes(string input)
{
    string output;
    helper(input, output);
}

int main()
{
    string input;
    cin >> input;

    printAllPossibleCodes(input);
    return 0;
}