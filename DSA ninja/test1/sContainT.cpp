#include <iostream>
using namespace std;

#include <string.h>
bool checksequenece(char large[], char *small)
{
    // BASE CASE
    if (strlen(small) == 0) // if small ended first that means we found the string in order in the large char arr
    {
        return true;
    }

    if (strlen(large) == 0) // if large gets over first before small than it means we didnt find the correct seq. 
    {
        return false;
    }

    if (large[0] == small[0]) // if equal than increase both small as well as large
    {
        return checksequenece(large + 1, small + 1);
    }
    else
    {
        return checksequenece(large + 1, small); // if not equal than only increse the large one as small is the array which we wanna find the large one
    }
}

int main()
{
    char large[10000];
    char small[10000];
    cin >> large;
    cin >> small;
    bool x = checksequenece(large, small);

    if (x)
        cout << "true";
    else
        cout << "false";
}
