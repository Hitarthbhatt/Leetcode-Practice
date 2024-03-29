/*
                -> Combination Sum <-

Given an array of distinct integers nums and a target integer target, return the number of possible combinations that add up to target.

The test cases are generated so that the answer can fit in a 32-bit integer.

    Example 1:
    Input: nums = [1,2,3], target = 4
    Output: 7
    Explanation:
    The possible combination ways are:
    (1, 1, 1, 1)
    (1, 1, 2)
    (1, 2, 1)
    (1, 3)
    (2, 1, 1)
    (2, 2)
    (3, 1)
    Note that different sequences are counted as different combinations.
*/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
    int solveMem(vector<int>& nums, int target, vector<int> &dp) {
        if (target == 0) return 1;
        if (target < 0) return 0;

        if (dp[target] != -1) return dp[target];

        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            ans += solveMem(nums, target - nums[i], dp);
        }

        dp[target] = ans;
        return dp[target];
    }

    int solveTab(vector<int>& nums, int target) {
        vector<int> dp(target + 1, 0);
        dp[0] = 1;

        for (int i = 0; i <= target; i++) {
            for (int j = 0; j < nums.size(); j++) {
                if (i >= nums[j]) {
                    dp[i] += (long long)dp[i - nums[j]];
                }
            }
        }
    
        return dp[target];
    }

public:
    int combinationSum4(vector<int>& nums, int target) {
        // vector<int> dp(target + 1, -1);
        // return solveMem(nums, target, dp);

        return solveTab(nums, target);
    }
};