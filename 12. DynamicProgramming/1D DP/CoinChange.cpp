/*
                -> Coin Change <-

You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.

    Example 1:
    Input: coins = [1,2,5], amount = 11
    Output: 3
    Explanation: 11 = 5 + 5 + 1
*/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
    int solveRec(vector<int>& coins, int x) {
        if (x < 0) return INT_MAX;
        if (x == 0) return 0;

        int mini = INT_MAX;
        for (int i = coins.size()-1; i >= 0; i--) {
            int ans = solveRec(coins, x-coins[i]);
            if (ans != INT_MAX) {
                mini = min(mini, ans+1);
            }
        }

        return mini;
    }

    int solveMem(vector<int>& coins, int x, vector<int> &dp) {
        if (x < 0) return INT_MAX;
        if (x == 0) return 0;

        if (dp[x] != -1) return dp[x];

        int mini = INT_MAX;
        for (int i = coins.size()-1; i >= 0; i--) {
            int ans = solveMem(coins, x-coins[i], dp);
            if (ans != INT_MAX) {
                mini = min(mini, ans+1);
            }
        }

        dp[x] = mini;

        return mini;
    }

    int solveTab(vector<int>& coins, int x) {
        vector<int> dp(x+1, INT_MAX);
        dp[0] = 0;

        int mini = INT_MAX;
        for (int i = 1; i <= x; i++) {
            for (int j = 0; j < coins.size(); j++) {
                if (i-coins[j] >= 0 && dp[i-coins[j]] != INT_MAX) {
                    dp[i] = min(dp[i], 1+dp[i-coins[j]]);
                }
            }
        }

        return dp[x];
    }


public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, -1);

        // int ans = solveRec(coins, amount);
        // int ans = solveMem(coins, amount, dp);
        int ans = solveTab(coins, amount);
        if (ans == INT_MAX) return -1;
        return ans;
    }
};