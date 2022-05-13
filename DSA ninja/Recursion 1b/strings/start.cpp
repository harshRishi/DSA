#include <iostream>
using namespace std;

int main()
{
    string s = "abc";
    cout << s << endl;

    string s1;
    s1 = "def";
    cout << s1 << endl;

    string *sp = new string;
    *sp = "ghi";
    cout << *sp << endl;
    cout << sp << endl;

    // STRING INPUT
    string si;
    cin >> si;
    cout << si << endl;

    string si1;
    cin.get(si1);
    cout << si1 << endl;
}