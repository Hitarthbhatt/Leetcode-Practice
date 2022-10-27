/*
                -> Subsets II <-

Given an integer array nums that may contain duplicates, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

    Example 1:
    Input: nums = [1,2,2]
    Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    void getSubsets(vector<int>& nums, vector<int> output, int index, vector<vector<int>>& ans) {
         ans.push_back(output);

        for (int i = index; i < nums.size(); i++) {
            if (i == index || nums[i] != nums[i - 1]) {
                int element = nums[i];
                output.push_back(element);
                getSubsets(nums, output, i+1, ans);
                output.pop_back();
            }
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        vector<vector<int>> ans;
        vector<int> output;
        sort(nums.begin(), nums.end());
    
        getSubsets(nums, output, 0, ans);

        return ans;
    }
};