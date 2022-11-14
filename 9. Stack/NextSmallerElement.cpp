/*
                -> Next smaller element in array.

Ex:- [2,1,4,3] -> [1,-1,3,-1]

T.C.:- O(n)
*/

#include <iostream>
#include <stack>
#include <vector>
 
using namespace std;
 
vector<int> nextSmallerElement(vector<int> &arr, int n) {

    stack<int> s;
    s.push(-1);
    vector<int> ans(n);

    for(int i = n - 1; i >= 0; i--) {
        int curr = arr[i];

        while (s.top() >= curr) {
            s.pop();
        }

        ans[i] = s.top();
        s.push(arr[i]);
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