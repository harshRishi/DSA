#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;
// there can only be one key possible

int main()
{
    unordered_map<string, int> m;

    // pair that we'll insert in our Map
    pair<string, int> p("abc", 1); // here we've used construtor [inBuilt]
    // insert Function
    m.insert(p);
    // shortCut to insert
    m["ghi"] = 2; // this will strone ghi as key and 2 as it's value

    // Access
    // this will search ghi in hashTable if found it will return it's value if not it'll make ghi and insert default value to it i.e 0
    cout << m["ghi"] << endl;    // less Safe
    cout << m.at("ghi") << endl; // warning if not found;
    if (m.count("ghi") > 0)      // count of a key can either be 1 or 0
    {
        cout << "Present" << endl;
    }
    
    // Size 
    m.size();

    // Erase
    m.erase("ghi");
}