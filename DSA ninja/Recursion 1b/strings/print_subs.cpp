#include <iostream> // see lecture number 4 in dsa recursion b
using namespace std;

void print_subs(string input, string output)
{
    //Base Case
    if (input.empty())
    {
        cout << output << endl;
        return;
    }
    print_subs(input.substr(1), output);            // Making input(1) to start from one and output should remain empty as it came
    print_subs(input.substr(1), output + input[0]); // making input(1) start from one and output include the part which has beem left apart when input(1) started from 1st position
}

int main()
{
    string input;
    cin >> input;

    string output = "";
    print_subs(input, output);
}