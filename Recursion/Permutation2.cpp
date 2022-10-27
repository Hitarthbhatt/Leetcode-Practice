/*
                -> Permutations II <-

Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.

    Example 1:
    Input: nums = [1,1,2]
    Output: [[1,1,2],
            [1,2,1],
            [2,1,1]]
 */


#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    void getPermutations(int size, vector<int>& output, vector<vector<int>>& ans, map<int, int>& checker) {
        // Base case
        if (output.size() >= size) {
            ans.push_back(output);
            return;
        }

        for (auto [key, count]: checker) {
            if (count == 0) continue;

            output.push_back(key);
            checker[key]--;
            getPermutations(size, output, ans, checker);
            // Backtracking.
            checker[key]++;
            output.pop_back();
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        map<int, int> checker;

        for (int i = 0; i < nums.size(); i++) {
            checker[nums[i]]++;
        }

        vector<vector<int>> ans;
        vector<int> output;
        int index = 0;
        getPermutations(nums.size(), output, ans, checker);
        return ans;
    }
};

