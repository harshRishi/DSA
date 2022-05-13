#include <unordered_map>
/*approch*/
/*
- store arr data in unordered map
- maintain maxlength and start index
- get minimum element in the head and check it's consecutiveNess 
- if found consecutiveNess than increase the count and updte the start 
*/

vector<int> longestConsecutiveIncreasingSequence(int *arr, int n)
{
    // Your Code goes here
    unordered_map<int, bool> map;
    int maxLength = 0, start;

    for (int i = 0; i < n; i++) // filled map with array key
    {
        map[arr[i]] = true;
    }

    for (int i = 0; i < n; i++)
    {
        if (map[arr[i] - 1] == false)
        {
            int currLen = 1;
            int currElement = arr[i];

            while (map[currElement + 1] == true)
            {
                currLen += 1;
                currElement += 1;
            }

            if (currLen > maxLength)
            {
                maxLength = currLen;
                start = arr[i];
            }
        }
    }

    vector<int> v; // to store the data from start to maxlength
    v.push_back(start);
    v.push_back(start + maxLength - 1);

    return v;
}