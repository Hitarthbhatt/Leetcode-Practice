/*
    -> Median of Two Sorted Arrays <-

Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

    Example 1:

    Input: nums1 = [1,3], nums2 = [2]
    Output: 2.00000
    Explanation: merged array = [1,2,3] and median is 2.
    Example 2:

    Input: nums1 = [1,2], nums2 = [3,4]
    Output: 2.50000
    Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.

 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> mergeSortedArray(vector<int>& nums1, vector<int>& nums2) {
        int firstIndex = 0;
        int secondIndex = 0;

        int firstArraySize = nums1.size();
        int secondArraySize = nums2.size();
        vector<int> mergerdArray;

        while (firstIndex < firstArraySize && secondIndex < secondArraySize) {
            if (nums1[firstIndex] < nums2[secondIndex]) {
                mergerdArray.push_back(nums1[firstIndex++]);
            } else {
                mergerdArray.push_back(nums2[secondIndex++]);
            }
        }

        while (firstIndex < firstArraySize) {
            mergerdArray.push_back(nums1[firstIndex++]);
        }

        while (secondIndex < secondArraySize) {
            mergerdArray.push_back(nums2[secondIndex++]);
        }
   
        return mergerdArray;
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        vector<int> mergedArray = mergeSortedArray(nums1, nums2);
        int size = mergedArray.size() - 1;

        if  (size % 2 != 0) {
            double median = (mergedArray[size/2] + mergedArray[size/2 + 1])/2.0;
            return median;
        } else {
            double median = mergedArray[size/2];
            return median;
        }
    }
};

