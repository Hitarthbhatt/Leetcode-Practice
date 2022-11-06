/*
            -> Reverse Pairs <-

Given an integer array nums, return the number of reverse pairs in the array.
A reverse pair is a pair (i, j) where:

0 <= i < j < nums.length and
nums[i] > 2 * nums[j].
 
    Example 1:
    Input: nums = [1,3,2,3,1]
    Output: 2
    Explanation: The reverse pairs are:
    (1, 4) --> nums[1] = 3, nums[4] = 1, 3 > 2 * 1
    (3, 4) --> nums[3] = 3, nums[4] = 1, 3 > 2 * 1
 */

#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

class Solution {
public:
    void merge(vector<int>& arr, int start, int end, int& totalPairs) {
    
        int mid = start + (end - start)/2;

        int left = start;
        int right = mid + 1;

        while (left <= mid && right <= end) {
            if ((long) arr[left] > (long) arr[right] * 2) {
                totalPairs += mid - left + 1;
                right++;
            } else {
                left++;
            }
        }

        sort(arr.begin() + start, arr.begin() + end + 1);
    }

    void mergeSort(vector<int>& arr, int start, int end, int& totalPairs) {

        if (start == end) return;
        int mid = start + (end - start)/2;

        mergeSort(arr, start, mid, totalPairs);
        mergeSort(arr, mid+1, end, totalPairs);
        merge(arr, start, end, totalPairs);
    }

    int reversePairs(vector<int>& nums) {
        int totalPairs = 0;
        mergeSort(nums, 0, nums.size() - 1, totalPairs);
        return totalPairs;
    }
};

