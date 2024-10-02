/*
                                -> Count derangements <-

A Derangement is a permutation of ‘N’ elements, such that no element appears in its original position. For example, an instance of derangement of {0, 1, 2, 3} is {2, 3, 1, 0}, because 2 present at index 0 is not at its initial position which is 2 and similarly for other elements of the sequence.

Given a number ‘N’, find the total number of derangements possible of a set of 'N’ elements.
*/

#include <iostream>
#include <vector>

#define MOD 1000000007

using namespace std;

int solveRec(int n) {
    if (n == 1) return 0;
    if (n == 2) return 1;
    
    int ans = (n - 1) * (solveRec(n - 1) + solveRec(n - 2));
    return ans;
}

int solveMem(int n, vector<int> dp) {
    if (n == 1) return 0;
    if (n == 2) return 1;
    
    if (dp[n] != -1) return dp[n];
    
    dp[n] = (n - 1) * (solveMem(n - 1, dp) + solveMem(n - 2, dp));
    return dp[n];
}

int solveTab(int n) {
    vector<int> dp(n+1, -1);
    dp[1] = 0;
    dp[2] = 1;
    
    for (int i = 3; i <= n; i++) {
        long long int first = dp[i - 2] % MOD;
        long long int second = dp[i - 1] % MOD;
        long long int sum = (first + second) % MOD;
        long long int ans = ((i-1) * sum) % MOD;
        dp[i] = ans;
    }
    
    return dp[n];
}

int solveBest(int n) {

    int prev2 = 0;
    int prev1 = 1;
    
    for (int i = 3; i <= n; i++) {
        long long int first = prev2 % MOD;
        long long int second = prev1 % MOD;
        long long int sum = (first + second) % MOD;
        long long int ans = ((i-1) * sum) % MOD;
        
        prev2 = prev1;
        prev1 = ans;
        
    }
    
    return prev1;
}

long long int countDerangements(int n) {
//     return solveRec(n);
    
//     vector<int> dp(n+1, -1);
//     return solveMem(n, dp);
    
//        return solveTab(n);
    
    return solveBest(n);
}