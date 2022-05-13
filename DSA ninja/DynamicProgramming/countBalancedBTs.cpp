#include<iostream>
using namespace std;
#include<cmath>
// Brute Force
int balancedBTs(int n) {
    // Write your code here
    if(n <= 1)     // Base Case
        return 1;
    
    int mod = (int)(pow(10, 9)) + 7; // this is used to shrink the size of digit
    
    // height diff can only be 0 or 1
    int left = balancedBTs(n -1); 
    int right = balancedBTs(n -2);
    
    int temp1 = (int)(((long)(left)*left)%mod); // here we've typeCasted the int to long than long to int to manage the size of digit
    int temp2 = (int)((2*(long)(left)*right) %mod);
    int ans = (temp1 + temp2) % mod;
    
    return ans;
}
// ************************** Using memoization ***********************
int helper(int n, int*ans) {
    // Base Case
    if(n <= 1) // only one combination is possible
        return 1;

    int mod = (int)(pow(10, 9)) + 7; // this is used to shrink the size of digit

    // before calling recusion check if output already exists
    if(ans[n] != -1)
        return ans[n];

    // calc if not found in ans array
    int left = helper(n -1, ans);
    int right = helper(n -2, ans);
    // here we've typeCasted the int to long than long to int to manage the size of digit
    int temp1 = (int) (((long(left) * left)) % mod);
    int temp2 = (int) ((2* (long)(left) * right) % mod);

    int result = (temp1 + temp2) % mod;
    // Save this to the ans array for further checks
    ans[n] = result;

    return ans[n];    
} 

int balancedBTs(int n) {
    // Write your code here
    int *memo = new int[n+1];
    for(int i = 0; i <= n; i++)
        memo[i] = -1;

    int result =  helper(n , memo);
    delete[] memo;
    return result;
}

// ****************************** Dynamic program Solution *************************************
int balancedBTs(int n) {
    // Write your code here
    int dp[n+1]; // Dp array to store the combinations

    // we know these cases have this ans
    dp[0] = dp[1] = 1;

    int mod = (int)(pow(10, 9)) + 7; // this is used to shrink the size of digit

    for(int i = 2; i <= n; i++) {

        int left = dp[i - 1];
        int right = dp[i - 2];

        // here we've typeCasted the int to long than long to int to manage the size of digit
        int temp1 = (int) (((long(left) * left)) % mod);
        int temp2 = (int) ((2* (long)(left) * right) % mod); // we've written 2 coz' at first left and right than rigth and left in both cases combination are diff

        dp[i] = (temp1 + temp2) % mod;
    }
    return dp[n]; // combination of n will be on nth position in the dp array after iterations
}

int main() {
    int n;
    cin >> n;
    cout << balancedBTs(n);
}



























