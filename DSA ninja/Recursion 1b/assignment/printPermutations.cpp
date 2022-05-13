#include <iostream>
#include <string>
using namespace std;

#include <iostream>
#include <string>
using namespace std;
//Print Permutation

void print(string input, string output)
{
    if (input.size() == 0)
    {
        cout << output << endl;
        return;
    }
    for (int i = 0; i < input.size(); i++)
    {
        // swap(input[0],input[i]);
        // print0(input.substr(1),input[0] + output);
        char ch = input[i];
        string roq = input.substr(0, i) + input.substr(i + 1);
        print(roq, output + ch);
    }
    // return;
}
void printPermutations(string input)
{
    string output = "";
    print(input, output);
}

int main()
{
    string input;
    cin >> input;
    printPermutations(input);
    return 0;
}