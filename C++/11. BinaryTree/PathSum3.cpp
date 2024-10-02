/*
                ->  Path Sum III <-

Given the root of a binary tree and an integer targetSum, return the number of paths where the sum of the values along the path equals targetSum.

The path does not need to start or end at the root or a leaf, but it must go downwards (i.e., traveling only from parent nodes to child nodes).

    Example 1:
    Input: root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8
    Output: 3
    Explanation: The paths that sum to 8 are shown.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void solve(TreeNode* root, int target, vector<int> v, int &ans) {
        if (root == NULL) return;

        v.push_back(root->val);

        solve(root->left, target, v, ans);
        solve(root->right, target, v, ans);

        long long sum = 0;
        for(int i = v.size()-1; i >= 0; i--) {
            sum += v[i];
            if (sum == target) ans++;
        }
    }

    int pathSum(TreeNode* root, int targetSum) {
        vector<int> v;
        int ans = 0;

        solve(root, targetSum, v, ans);

        return ans;
    }
};