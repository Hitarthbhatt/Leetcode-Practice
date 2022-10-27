/*
            -> Subsets <-

Given an integer array nums of unique elements, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

    Example 1:
    Input: nums = [1,2,3]
    Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    void getSubsets(vector<int>& nums, vector<int> output, int index, vector<vector<int>>& ans) {

        if (index >= nums.size()) {
            ans.push_back(output);
            return;
        }

        // Exclude Element.
        getSubsets(nums, output, index+1, ans);
        
        // Include Element.
        int element = nums[index];
        output.push_back(element);
        getSubsets(nums, output, index+1, ans);
    }


public:
    vector<vector<int>> subsets(vector<int>& nums) {

        vector<vector<int>> ans;
        vector<int> output;
    
        getSubsets(nums, output, 0, ans);

        return ans;
    }
};

