#include <iostream>
#include <stack>
using namespace std;

// NOTE : here we have used recursion as our temp stack as in backGround it works as an stack so we first revser the i/p in input using recursion and then we reversed it agin into extra than again reversed it to the original input stack in the expected order

void reverseStack(stack<int> &input, stack<int> &extra)
{
    //Write your code here
    // Base Case
    if (input.size() == 1 || input.empty())
    {
        return;
    }
    int temp = input.top(); // saving the top most element of input in temp and poppping it out so that on rest of stack we can call recursion
    input.pop();

    // Recursive Call
    reverseStack(input, extra); // here input will be one less as input.pop() will remove the top most element

    while (!input.empty()) // copying all elements from input to extra in reverse order
    {
        int val = input.top();
        input.pop(); // input getting smaller

        extra.push(val);
    }
    extra.push(temp); // here we copied the temp to the extra stack top

    //Now we can copy all extra elements into the input stack back in reverse order as expected
    while (!extra.empty())
    {
        int val = extra.top();
        extra.pop();

        input.push(val);
    }
}

int main()
{
    stack<int> input, extra;
    int size;
    cin >> size;

    for (int i = 0, val; i < size; i++)
    {
        cin >> val;
        input.push(val);
    }

    reverseStack(input, extra);

    while (!input.empty())
    {
        cout << input.top() << " ";
        input.pop();
    }
}