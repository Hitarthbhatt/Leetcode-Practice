/*
                -> Next greater element in array.

Provide index of next greater element of ith index element.

Ex:- [2,1,4,3] -> [2,2,0,0]

T.C.:- O(n)
*/

#include <iostream>
#include <stack>
#include <vector>
 
using namespace std;
 
vector<int> nextSmallerElement(vector<int> &arr, int n) {

    stack<int> s;
    vector<int> ans(n, 0);

    for(int i = n - 1; i >= 0; i--) {
        int curr = arr[i];

        while (!s.empty() && arr[s.top()] <= curr) {
            s.pop();
        }

        if (!s.empty()) {
            ans[i] = s.top();
        }

        s.push(i);
    }
    return ans;
}

int main() {
 
    vector<int> nums;

    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(4);
    nums.push_back(3);

    vector<int> ans = nextSmallerElement(nums, nums.size());

    for (int i = 0; i < nums.size(); i++) {
        cout << ans[i] << " ";
    }

    cout << endl;

    return 0;
}