/*
            -> Sum of minimum and maximum elements of all subarrays of size k. <-

Given an array of both positive and negative integers, the task is to compute sum of minimum and maximum elements of all sub-array of size k.

    Examples: 

    Input : arr[] = {2, 5, -1, 7, -3, -1, -2}  
            K = 4
    Output : 18
    Explanation : Subarrays of size 4 are : 
     {2, 5, -1, 7},   min + max = -1 + 7 = 6
     {5, -1, 7, -3},  min + max = -3 + 7 = 4      
     {-1, 7, -3, -1}, min + max = -3 + 7 = 4
     {7, -3, -1, -2}, min + max = -3 + 7 = 4   
     
     Missing sub arrays - 
     
     {2, -1, 7, -3}
     {2, 7, -3, -1}
     {2, -3, -1, -2}
     {5, 7, -3, -1}
     {5, -3, -1, -2}
     and few more -- why these were not considered??
     Considering missing arrays result coming as 27
     
     Sum of all min & max = 6 + 4 + 4 + 4 => 18               
*/

#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int solve(vector<int> nums, int n, int k) {

    deque<int> maxi(k);
    deque<int> mini(k);

    // Addition of first k window.

    for (int i = 0; i < k; i++) {

        while (!maxi.empty() && nums[maxi.back()] <= nums[i]) {
            maxi.pop_back();
        }

        while (!mini.empty() && nums[mini.back()] >= nums[i]) {
            mini.pop_back();
        }

        maxi.push_back(i);
        mini.push_back(i);
    }

    int ans = 0;
    for (int i = k; i < n; i++) {

        ans = nums[maxi.front()] + nums[mini.front()];

        // -> Next Window <-
        // Removal
        while (!maxi.empty() && i - maxi.front() >= k) {
            maxi.pop_front();
        }

        while (!mini.empty() && i - maxi.front() >= k) {
            mini.pop_front();
        }

        // Addition
        while (!maxi.empty() && nums[maxi.back()] <= nums[i]) {
            maxi.pop_back();
        }

        while (!mini.empty() && nums[mini.back()] >= nums[i]) {
            mini.pop_back();
        }

        maxi.push_back(i);
        mini.push_back(i);
    }

    ans = nums[maxi.front()] + nums[mini.front()];
    return ans;
}