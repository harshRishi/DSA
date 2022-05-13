#include <unordered_map>

int highestFrequency(int arr[], int n)
{
    // Write your code here
    unordered_map<int, int> freqCheck;
    for (int i = 0; i < n; i++)
    {
        freqCheck[arr[i]]++;
    }

    int max = -1, ans;
    for (int i = 0; i < n; i++)
    {
        if (freqCheck[arr[i]] > max)
        {
            max = freqCheck[arr[i]];
            ans = arr[i];
        }
    }
    /* // using itrator
    <key,value>p
    p.first
    p.second
    
    for(auto i:freqCheck){
    	if(i.second>max){
        	max=i.second;
            ans=i.first;
        }
    }
	*/
    return ans;
}