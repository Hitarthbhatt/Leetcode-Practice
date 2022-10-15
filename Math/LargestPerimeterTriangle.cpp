/*
                -> Largest Perimeter Triangle <- 

Given an integer array nums, return the largest perimeter of a triangle with a non-zero area, formed from three of these lengths. If it is impossible to form any triangle of a non-zero area, return 0.
    
    Example 1:
    Input: nums = [2,1,2]
    Output: 5
 */

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    int largestPerimeter(vector<int>& nums) {

        sort(nums.begin(), nums.end(), greater<int>());

        int maxSum = 0;

        for (int i = 0; i < nums.size() - 2; i++) {
            if (getTriangleArea(nums, i) > 0.0) { 
                maxSum = nums[i] + nums[i + 1] + nums[i + 2];
                break;
            }
        }

        return maxSum;
    }

    double getTriangleArea(vector<int>& nums, int index) {
        // Heron's Area of Triangle.

        double sum = 0;
        for (int i = index; i < index + 3; i++) {
            sum += nums[i];
        }

        sum = sum/2;
        double result = sqrt(sum * (sum - nums[index]) * (sum - nums[index + 1]) * (sum - nums[index + 2]));

        return result;
    }
};