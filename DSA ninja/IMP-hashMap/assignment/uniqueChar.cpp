#include <unordered_map>
string uniqueChar(string str)
{
    // Write your code here
    unordered_map<char, int> map;
    string ans = ""; // initialise the empty string

    int i = 0;
    for (; i < str.length(); i++)
    {
        if (map[str[i]] <= 0) // if it ins't already in the map than only insert that perticular ch in the ans string
        {
            ans += str[i]; // add this new str[i] to our empty string and keep on adding
            map[str[i]]++; // increase the freq in map
        }
    }
    return ans;
}