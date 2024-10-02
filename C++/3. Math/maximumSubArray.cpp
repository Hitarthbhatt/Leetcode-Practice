/*
                -> Maximum Subarray (Kadane’s Algorithm). <-

Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

A subarray is a contiguous part of an array.

    Example 1:
    Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
    Output: 6
    Explanation: [4,-1,2,1] has the largest sum = 6.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        return maxSubArray(nums, nums.size());
    }
    
    int maxSubArray(vector<int>& nums, int size) {
        int maxSoFar = INT_MIN, maxSum = 0;
        
        for (int i = 0; i < size; i++) {
            maxSum += nums[i];
            maxSoFar = max(maxSoFar, maxSum);
            maxSum = max(0, maxSum);
        }
        
        return maxSoFar;
    }
    
};