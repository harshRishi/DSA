#include <bits/stdc++.h>
using namespace std;

/* printing
#include<bits/stdc++.h>
using namespace std;

string dial(int key){
    string m[10]; // string of array m with size 10
    m[0]="";
    m[1]="";
    m[2]="abc";
    m[3]="def";
    m[4]="ghi";
    m[5]="jkl";
    m[6]="mno";
    m[7]="pqrs";
    m[8]="tuv";
    m[9]="wxyz";
    return m[key];
}

void printK(int num, string s){
    if(num<=0){
        cout << s << '\n';
        return;
    }
    int digit = num%10;
    string chars = dial(digit);
    for(int i=0;i<chars.length();i++){
        printK(num/10, chars[i]+s);
    }
}

void printKeypad(int num)
{
    printK(num, ""); 
}
*/

 //  returning
vector<string> keypad(int n, vector<string> keyChar)
{
    if (n <= 1)
    {
        vector<string> output;
        output.push_back("");
        return output;
    }
    int lastDigit = n % 10;
    int smallNum = n / 10;
    vector<string> smalloutput;
    vector<string> output;

    smalloutput = keypad(smallNum, keyChar);
    string letters = keyChar[lastDigit];

    for (int i = 0; i < letters.length(); i++)
    {
        for (int j = 0; j < smalloutput.size(); j++)
        {
            output.push_back(smalloutput[j] + letters[i]);
        }
    }
    return output;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> keyChar = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> output = keypad(n, keyChar);
        for (int i = 0; i < output.size(); i++)
            cout << output[i] << '\n';
    }
    // write your code here
    return 0;
}

/*
string letter_r(int n)
{
    if (n == 1)
        return "";
    if (n == 2)
    {
        return "abc";
    }
    if (n == 3)
    {
        return "def";
    }
    if (n == 4)
    {
        return "ghi";
    }
    if (n == 5)
    {
        return "jkl";
    }
    if (n == 6)
    {
        return "mno";
    }
    if (n == 7)
    {
        return "pqrs";
    }
    if (n == 8)
    {
        return "tuv";
    }
    if (n == 9)
    {
        return "wxyz";
    }

    //return "";
}

int keypad(int num, string output[])
{

    if (num == 0)
    {
        output[0] = "";
        return 1;
    }

    int digit = num % 10;
    string temp[1000];
    int ans = keypad(num / 10, temp);
    string f = letter_r(digit);

    int k = 0;
    for (int i = 0; i < f.length(); i++)
    {
        for (int j = 0; j < ans; j++)
        {
            output[k++] = temp[j] + f[i];
        }
    }

    return k;
}
*/