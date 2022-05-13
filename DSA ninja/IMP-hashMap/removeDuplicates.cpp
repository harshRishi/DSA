#include <iostream>
using namespace std;
#include <unordered_map>
#include <vector>

vector<int> removeDuplicates(int *arr, int size)
{
    vector<int> ans;
    unordered_map<int, bool> check;
    for (int i = 0; i < size; i++)
    {
        if (check.count(arr[i]) > 0) // if we found arr[i] th element in the map than do nothing
        {
            continue;
        }
        ans.push_back(arr[i]);
        // 2 ways to do it
        /*
        - make pair object with key and value and insert
        pair<int, bool> p(arr[i], true);
        check.push(p);
        - or use this shortcut
        */
        check[arr[i]] = true;
    }
    return ans;
}

int main()
{
    int a[] = {1, 2, 3, 3, 2, 1, 4, 3, 6, 5, 5};
    vector<int> output = removeDuplicates(a, 11);
    for (int i = 0; i < output.size(); i++)
    {
        cout << output[i] << endl;
    }
}