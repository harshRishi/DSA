#include <iostream>
using namespace std;

int main()
{
    char str[] = "abcde"; // this is correct coz here abcde is stored in temp then  that temp is been copied in out str string for further oprations
    char *pstr = "abcde";  // this is wrong coz here abcde will be stored in a temp storage and then this strpinter will point to this temp storage

    char input[] = "abc";
    char *p = &input[0];

    cout << input << endl;
    cout << p << endl;

    char ch = "a";
    // char *pch = &ch; // this will not print because it will run untill it reaches the null char
}