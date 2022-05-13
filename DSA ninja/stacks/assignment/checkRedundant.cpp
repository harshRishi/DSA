#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool checkRedundantBrackets(string expression)
{
    // Write your code here
    stack<int> s;
    for (int i = 0; i < expression.length(); i++) // here we've created a stack out of our expression
    {
        s.push(expression[i]);

        if (s.top() == ')') // we'll only enter this loop if we encounter the closing braks this means a pair of braket just ended
        {
            s.pop(); // removing the closing bracket and than we'll start count
            int count = 0;
            while (s.top() != '(')
            {
                s.pop();
                count++;
            }
            s.pop(); // this is to remove the opening brack which is not counted but needs to be removed
            if (count == 0 || count == 1) // this means there is no valuable info bw brackets
            {
                return true; // defining yes this expression is redundant
            }
        }
    }
    return false;
}

int main()
{
    string input;
    cin >> input;
    cout << ((checkRedundantBrackets(input)) ? "true" : "false");
}