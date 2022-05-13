#include <iostream>
#include <stack>
using namespace std;

/*
int *stockSpan(int *price, int size)  // Time Complexcity O(n ^ 2)
{
    // Write your code here
    int *output = new int[size];
    output[0] = 1;

    for (int i = 1; i < size; i++)
    {
        int span = 1;
        if (price[i] > price[i - 1])
        {
            for (int j = i - 1; price[i] > price[j] && j != -1; j--) // here we are traversing back from i-1 position to 0th position meanWhile check price of ith should be greateer than jth if yes to boththe condition than increase span by 1;
            {
                span++;
            }
        }
        output[i] = span;
    }
    return output;
}
*/

int *stockSpan(int *price, int size) // Time Complexcity O(n)
{
    // Create a stack and push index of first
    // element to it
    stack<int> st;
    st.push(0);

    int *S = new int[size];
    // Span value of first element is always 1
    S[0] = 1;

    // Calculate span values for rest of the elements
    for (int i = 1; i < size; i++)
    {
        // Pop elements from stack while stack is not
        // empty and top of stack is smaller than
        // price[i]
        while (!st.empty() && price[st.top()] < price[i])
            st.pop();

        // If stack becomes empty, then price[i] is
        // greater than all elements on left of it,
        // i.e., price[0], price[1], ..price[i-1].  Else
        // price[i] is greater than elements after
        // top of stack
        S[i] = (st.empty()) ? (i + 1) : (i - st.top());

        // Push this element to stack
        st.push(i);
    }
    return S;
}

int main()
{
    int size;
    cin >> size;

    int *input = new int[size];
    for (int i = 0; i < size; i++)
    {
        cin >> input[i];
    }

    int *output = stockSpan(input, size);
    for (int i = 0; i < size; i++)
    {
        cout << output[i] << " ";
    }

    cout << "\n";

    delete[] input;
    delete[] output;
}