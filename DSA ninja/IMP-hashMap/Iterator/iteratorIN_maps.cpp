#include <iostream>
using namespace std;
#include <string>
#include <unordered_map>

// there should not be any perticular order as it is an UnorderedMap

int main()
{
    unordered_map<string, int> ourMap;
    ourMap["abc"] = 1;
    ourMap["abc2"] = 2;
    ourMap["abc3"] = 3;
    ourMap["abc4"] = 4;
    ourMap["abc5"] = 5;
    ourMap["abc6"] = 6;

    // here we'll going to create an iterator which have folling formate for unorderedMaps
    // Read it from right to left
    unordered_map<string, int>::iterator it = ourMap.begin(); // now iterator is pointing towards an unordered_map's beinging (key-value pair{string and int respt)} with name OurMap

    // now we have to travel through this ourMap (an Unordered_map)
    while (it != ourMap.end()) // ourMap.end() is not the end point of the map it is actually the point after our map actually ends
    {
        // Now as "it" (iterator) is pointing towards beinging of the map {which is an pair of strings and int as it's key-value} so to print we need arrow function pointing towards fist and second of pair
        cout << "key : " << it->first /*key*/ << " value : " << it->second /*value*/ << endl;
        it++;
    }
}