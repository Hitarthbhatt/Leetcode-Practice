/*
                -> Binary Tree Right Side View <-

Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

    Example 1:
    Input: root = [1,2,3,null,5,null,4]
    Output: [1,3,4]
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
    void solve(TreeNode* root, vector<int> &ans, int level) {
        if (root == NULL) return;
        
        if (level == ans.size()) {
            ans.push_back(root->val);
        }
        
        solve(root->right, ans, level + 1);
        solve(root->left, ans, level + 1);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        int level = 0;
        solve(root, ans, level);
        
        return ans;
    }
};