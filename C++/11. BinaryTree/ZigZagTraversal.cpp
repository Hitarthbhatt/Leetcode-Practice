/*
        -> Binary Tree Zigzag Level Order Traversal <-

Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).

    Example 1:
    Input: root = [3,9,20,null,null,15,7]
    Output: [[3],[20,9],[15,7]]
*/

#include <iostream>
#include <vector>
#include <queue>

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        
        if (root == NULL) return result;
        
        queue<TreeNode*> q;
        q.push(root);
        
        bool leftToRight = true;
        
        while(!q.empty()) {
            int size = q.size();
            vector<int> ans(size);
            
            for(int i = 0; i < size; i++) {
                TreeNode* frontNode = q.front();
                q.pop();
                
                int index = leftToRight ? i : size - i - 1;
                ans[index] = frontNode->val;
                
                if (frontNode->left) {
                    q.push(frontNode->left);
                }
                
                if (frontNode->right) {
                    q.push(frontNode->right);
                }
            }
            
            // Change direction.
            leftToRight = !leftToRight;
            
            result.push_back(ans);
        }
        
        return result;
    }
};