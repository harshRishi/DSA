#include <iostream>
#include <string>
#include <stack>
using namespace std;

int countBracketReversals(string input)
{
    // Write your code here
    if (input.length() % 2 != 0) // in this case expression can not be balanced
    {
        return -1;
    }
    stack<char> s;
    int count = 0;

    for (int i = 0; i < input.length(); i++) // by doing this we have removed all the balanced pair of bracks from the stack
    {
        if (input[i] == '{')
        {
            s.push(input[i]);
        }
        else if (s.empty())
        {
            s.push(input[i]);
        }
        else if (!s.empty() && s.top() == '{')
        {
            s.pop();
        }
        else if (!s.empty() && s.top() != '{')
        {
            s.push(input[i]);
        }
    }
    char c1, c2;
    while (!s.empty()) // here we will make compair bw top two char from the stack so count total reversals untill stack dies
    {
        c1 = s.top();
        s.pop();
        c2 = s.top();
        s.pop();

        if (c1 != c2) // if not equal than we need 2 reversals to balance them.
        {
            count += 2;
        }
        else
        {
            count++;
        }
    }
    return count;
}
int main()
{
    string input;
    cin >> input;
    cout << countBracketReversals(input);
}
