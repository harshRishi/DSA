#include <iostream>
#include <stack>
using namespace std;
// #include "testClass.h"

int main()
{
    stack<int> s1;
    s1.push(100);
    s1.push(101);
    s1.push(102);
    s1.push(103);
    s1.push(104);

    cout << s1.top() << endl;

    s1.pop(); // InBuilt stack doesn't return any value, this inbuilt pop() only deletes the top most values
    s1.pop();
    s1.pop();

    cout << s1.size() << endl;
    cout << s1.empty() << endl;
}

#include <iostream>
#include <stack>
using namespace std;