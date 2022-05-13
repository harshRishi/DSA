#include <iostream>
using namespace std;

int length(char str[])
{
    if (str[0] == '\0')
    {
        return 0;
    }

    int smallString = length(str + 1);
    return 1 + smallString;

    // Method 2
    // int count = 0;
    // return (++count) + length(str - 1);
}

int main()
{
    char str[100];
    cin >> str;

    cout << length(str) << endl;
}