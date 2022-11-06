/*
                -> Find All Duplicates in an Array <-

Given an integer array nums of length n where all the integers of nums are in the range [1, n] and each integer appears once or twice, return an array of all the integers that appears twice.

You must write an algorithm that runs in O(n) time and uses only constant extra space.

    Example 1:
    Input: nums = [4,3,2,7,8,2,3,1]
    Output: [2,3]

    Constraints:
    - n == nums.length
    - 1 <= n <= 105
    - 1 <= nums[i] <= n
    - Each element in nums appears once or twice.
 */

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
       return superOptimized(nums);
    }
    
    vector<int> superOptimized(vector<int>& nums) {
        vector<int> result;
        
        for (int i = 0; i < nums.size(); i++) {
            int index = abs(nums[i]) - 1;
            if (nums[index] < 0) {
                result.push_back(abs(nums[i]));
            } else {
                nums[index] = -nums[index];
            }
        }

        // Time Complexity -> O(n)
        // Space Complexity -> O(1)
        
        return result;
    }
    
    vector<int> optimizedSol(vector<int>& nums) {
        map<int, int> data;
        vector<int> result;
        
        for (int i = 0; i < nums.size(); i++) {
            data[nums[i]] += 1;
        }
        
        for (auto &val: data) {
            if (val.second > 1) {
                result.push_back(val.first);
            }
        }
        
        // Time Complexity -> O(n)
        // Space Complexity -> O(n)

        return result;
    }
};