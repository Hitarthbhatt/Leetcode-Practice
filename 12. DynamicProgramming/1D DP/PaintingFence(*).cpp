/*
                    -> Painting Fence (IMP) <- 

Ninja has given a fence, and he gave a task to paint this fence. The fence has 'N' posts, and Ninja has 'K' colors. Ninja wants to paint the fence so that not more than two adjacent posts have the same color.
Ninja wonders how many ways are there to do the above task, so he asked for your help.
Your task is to find the number of ways Ninja can paint the fence. Print the answer modulo 10^9 + 7.
    
    Example:
    Input: 'N' = 3, 'K' = 2
    Output: 6

    Say we have the colors with the numbers 1 and 0. We can paint the fence with 3 posts with the following different combinations.

    110, 001, 101, 100, 010, 011
*/

#include<iostream>
#include<vector>
#define mod 1000000007

using namespace std;

int add(int a, int b) {
   return (a%mod + b%mod) % mod;    
}

int mul(int a, int b) {
   return (a%mod * 1LL * b%mod) % mod;    
}

int solveMem(int n, int k, vector<int>& dp) {
    if (n == 1) return k;
    if (n == 2) return add(k, mul(k, k-1));
    
    if (dp[n] != -1) return dp[n];
    
    dp[n] = add(mul(solveMem(n-2, k, dp), k-1),
               mul(solveMem(n-1, k, dp), k-1));
    return dp[n];
}

int solveTab(int n, int k) {
    vector<int> dp(n+1, 0);
    dp[1] = k;
    dp[2] = add(k, mul(k, k-1));
    
    for (int i = 3; i <= n; i++) {
        dp[i] = add(mul(dp[i-2], k-1),
                   mul(dp[i-1], k-1));
    }
    return dp[n];
}

int solveTabSO(int n, int k) {
    int prev2 = k;
    int prev1 = add(k, mul(k, k-1));
    
    for (int i = 3; i <= n; i++) {
        int ans = add(mul(prev2, k-1),
                   mul(prev1, k-1));
        prev2 = prev1;
        prev1 = ans;
    }
    return prev1;
}

int numberOfWays(int n, int k) {
//     vector<int> dp(n+1, -1);
//     return solveMem(n, k, dp);
    
    return solveTabSO(n, k);
}
