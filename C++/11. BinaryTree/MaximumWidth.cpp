/*
                    -> Maximum Width of Binary Tree <-

Given the root of a binary tree, return the maximum width of the given tree.

The maximum width of a tree is the maximum width among all levels.

The width of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes), where the null nodes between the end-nodes that would be present in a complete binary tree extending down to that level are also counted into the length calculation.

It is guaranteed that the answer will in the range of a 32-bit signed integer.

Example 1:
Input: root = [1,3,2,5,3,null,9]
Output: 4
Explanation: The maximum width exists in the third level with length 4 (5,3,null,9).

                -> IMP <- (For Tree)
            
            Left Index = 2 * idx + 1
            Rigth Index = 2 * idx + 2
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
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL)
            return 0;
        
        int ans = 1;
        queue<pair<TreeNode*, int>> q;
        
        q.push({root, 0});
        
        while(!q.empty()) {
            int cnt = q.size();
            int start = q.front().second;
            int end = q.back().second;
            
            ans = max(ans, end-start + 1);
            
            for(int i = 0; i <cnt; i++) {
                pair<TreeNode*, int> p = q.front();
                int idx = p.second;
                q.pop();
                
                if(p.first->left)
                    q.push({p.first->left, (long long)2 * idx + 1});
                
                if(p.first->right)
                    q.push({p.first->right, (long long) 2 * idx + 2});
            }
        }
        
        return ans;
        
    }
};