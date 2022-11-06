/*
                -> Next Permutation <-
A permutation of an array of integers is an arrangement of its members into a sequence or linear order.

For example, for arr = [1,2,3], the following are all the permutations of arr: [1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1].
If such arrangement is not possible, the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).

For example, the next permutation of arr = [1,2,3] is [1,3,2].
Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not have a lexicographical larger rearrangement.
Given an array of integers nums, find the next permutation of nums.

The replacement must be in place and use only constant extra memory.
*/

/*
                                -> Solution <-

1. A sequence sorted in descending order does not have the next permutation. For example “edcba” does not have the next permutation.
2. For a sequence that is not sorted in descending order for example “abedc”, we can follow these steps.  
    a) Traverse from the right and find the first item that is not following the ascending order. For example in “abedc”, the character ‘b’ does not follow the ascending order.
    b) Swap the found character with the closest greater (or smallest greater) element on the right side of it. In the case of “abedc”, we have ‘c’ as the closest greater element. After swapping ‘b’ and ‘c’, the string becomes “acedb”.
    c) After swapping, reverse the string after the position of the character found in step a. After reversing the substring “edb” of “acedb”, we get “acbde” which is the required next permutation. 

* Optimizations in steps b) and c) 
    a) Since the sequence is sorted in decreasing order, we can use binary search to find the closest greater element. 

    c) Since the sequence is already sorted in decreasing order (even after swapping as we swapped with the closest greater), we can get the sequence sorted (in increasing order) after reversing it.                 
*/


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void reverseArray(vector<int>& nums, int start, int end) {
        while (start <= end) {
            swap(nums[start++], nums[end--]);
        }
    }

    int bSearch(vector<int>& nums, int start, int end, int key) {
        int mid = start + (end - start)/2;
        int index = -1;
        while (start <= end) {

            if (nums[mid] <= key) {
                end = mid - 1;
            } else {
                start = mid + 1;
                if (index == -1 || nums[index] >= nums[mid]) {
                    index = mid;
                }
            }

            mid = start + (end - start)/2;
        }

        return index;
    }

    void nextPermutation(vector<int>& nums) {
        int size = nums.size();
        int i = size - 2;

        while (i >= 0 && nums[i] >= nums[i+1]) i--;

        if (i < 0) { // Array Sorted in desc. order.
            reverseArray(nums, 0, size - 1);
        } else {
            int index = bSearch(nums, i+1, size - 1, nums[i]);
            swap(nums[i], nums[index]);
            reverseArray(nums, i+1, size - 1);
        }
    }
};

