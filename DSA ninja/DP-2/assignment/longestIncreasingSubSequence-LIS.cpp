int longestIncreasingSubsequence(int *arr, int n)
{
    // Write your code here
    int *output = new int[n]; // this will going to store Lis till ith arr element
    // what we know
    output[0] = 1; // LIS at 0th index will be 1 as starting and ending index is same in this case

    // check for each ith element in the arr
    for (int i = 1; i < n; i++)
    {                  // initialize first index with one
        output[i] = 1; // worst case where this is the only lis, ie, element itself
        // now seach the output backward from ith index
        for (int j = i - 1; j >= 0; j--)
        {
            // if we found something less than the current element update the lis and if not that continue
            if (arr[j] >= arr[i])
            { // current element is smaller than prev element that mean not increasing
                continue;
            }
            int possibleAns = output[j] + 1; // save the lis of jth index including ith element ie, add one to the sequence count
            if (possibleAns > output[i])
                output[i] = possibleAns;
        }
    }
    // by this time output will going to have all the unique lis, all we need to do is find the largest lis in the output
    int maxLength = 0;
    for (int i = 0; i < n; i++)
    {
        if (maxLength < output[i])
            maxLength = output[i];
    }
    delete[] output;
    return maxLength;
}