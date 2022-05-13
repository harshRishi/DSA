#include <iostream>
#include <string>
using namespace std;

#include <string>
#include <iostream>
using namespace std;

int i = 0;
void print(string input, string output[], string asf)
{
    if (input.size() == 0)
    {
        output[i++] = asf;
        return;
    }
    for (int i = 0; i < input.size(); i++)
    {
        // swap(input[0],input[i]);
        // print0(input.substr(1),input[0] + output);
        char ch = input[i];
        string roq = input.substr(0, i) + input.substr(i + 1);
        print(roq, output, asf + ch);
    }
    // return;
}
int returnPermutations(string input, string output[])
{
    print(input, output, "");
    return 10000;
}

int main()
{
    string input;
    cin >> input;
    string output[10000];
    int count = returnPermutations(input, output);
    for (int i = 0; i < count && i < 10000; i++)
    {
        cout << output[i] << endl;
    }
    return 0;
}
