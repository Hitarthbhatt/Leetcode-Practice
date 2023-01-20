/*
                        -> House Robber <-
                (Maximum Sum of Non-Adjacent Elements)

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

    Example 1:
    Input: nums = [1,2,3,1]
    Output: 4
    Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
    Total amount you can rob = 1 + 3 = 4.
*/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int solveRec(vector<int>& nums, int n) {
        if (n < 0) return 0;
        if (n == 0) return nums[0];

        int inc = solveRec(nums, n - 2) + nums[n];
        int exc = solveRec(nums, n - 1) + 0;

        return max(inc, exc);
    }

    int solveMem(vector<int>& nums, int n, vector<int> &dp) {
        if (n < 0) return 0;
        if (n == 0) return nums[0];

        if (dp[n] != 0) {
            return dp[n];
        }

        int inc = solveMem(nums, n - 2, dp) + nums[n];
        int exc = solveMem(nums, n - 1, dp) + 0;

        dp[n] = max(inc, exc);
        return dp[n];
    }

    int solveTab(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n, 0);
        dp[0] = nums[0];

        for (int i = 1; i < n; i++) {
            int inc = (i >= 2 ? dp[i-2] : 0) + nums[i];
            int exc = dp[i-1] + 0;
            dp[i] = max(inc, exc);
        }

        return dp[n-1];
    }

    int solveBest(vector<int>& nums) {
        int n = nums.size();

        int prev2 = 0;
        int prev1 = nums[0];

        for (int i = 1; i < n; i++) {
            int inc = prev2 + nums[i];
            int exc = prev1 + 0;
            
            int ans = max(inc, exc);

            prev2 = prev1;
            prev1 = ans;
        }

        return prev1;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        // return solveRec(nums, n-1);

        // vector<int> dp(n, 0);
        // return solveMem(nums, n-1, dp);

        // return solveTab(nums);

        return solveBest(nums);
    }
};