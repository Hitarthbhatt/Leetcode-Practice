/*
                    ->  Min Cost Climbing Stairs <-

You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you pay the cost, you can either climb one or two steps.

You can either start from the step with index 0, or the step with index 1.

Return the minimum cost to reach the top of the floor.

    Example 1:
    Input: cost = [10,15,20]
    Output: 15
    Explanation: You will start at index 1.
    - Pay 15 and climb two steps to reach the top.
    The total cost is 15.
*/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int solve1(vector<int> &cost, int n) { // Recurssion
        if (n == 0) return cost[0];
        if (n == 1) return cost[1];

        int ans = cost[n] + min(solve1(cost, n-1), solve1(cost, n-2));
        return ans;
    }

    int solve2(vector<int> &cost, int n, vector<int> &dp) { // Recursion + Memorization
        if (n == 0) return cost[0];
        if (n == 1) return cost[1];

        if (dp[n] != -1) {
            return dp[n];
        }

        dp[n] = cost[n] + min(solve2(cost, n-1, dp), solve2(cost, n-2, dp));
        return dp[n];
    }

    int solve3(vector<int> &cost, int n) { // Tabulation (Bottom Up)
        vector<int> dp(n + 1);

        dp[0] = cost[0];
        dp[1] = cost[1];

        for (int i = 2; i < n; i++) {
            dp[i] = cost[i] + min(dp[i-1], dp[i-2]);   
        }

        int ans = min(dp[n-1], dp[n-2]);
        return ans;
    }

    int solve4(vector<int> &cost, int n) { // Tabulation (Bottom Up) + Space Optimize

        int prev2 = cost[0];
        int prev1 = cost[1];

        for (int i = 2; i < n; i++) {
            int curr = cost[i] + min(prev1, prev2);   
            prev2 = prev1;
            prev1 = curr;
        }

        int ans = min(prev1, prev2);
        return ans;
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        
        // Recurssion
        // int ans = min(solve1(cost, n-1), solve1(cost, n-2)); 

        // Recursion + Memorization
        // vector<int> dp(n+1, -1);
        // int ans = min(solve2(cost, n-1, dp), solve2(cost, n-2, dp));

        // Tabulation (Bottom Up)
        // int ans = solve3(cost, n);

        // Tabulation (Bottom Up) + Space Optimize
        int ans = solve4(cost, n);

        return ans;
    }
};