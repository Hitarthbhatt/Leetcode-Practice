/*
                -> First Negative Integer In Every K Window <-
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> printFirstNegativeInteger(vector<int> nums, int n, int k) {

    deque<int> dq;
    vector<int> ans;

    // Process first window of K size.
    for (int i = 0; i < k; i++) {
        if (nums[i] < 0) {
            dq.push_back(i);
        }
    }

    // Store ans for first k sizes window
    if (dq.size() > 0) {
        ans.push_back(nums[dq.front()]);
    } else {
        ans.push_back(0);
    }

    // Process for remaining.
    for (int i = k; i < nums.size(); i++) {

        if (!dq.empty() && (i - dq.front()) >= k) {
            dq.pop_front();
        }

        if (nums[i] <= 0) {
            dq.push_back(i);
        }

        if (dq.size() > 0) {
            ans.push_back(nums[dq.front()]);
        } else {
            ans.push_back(0);
        }
    }

    return ans;
}