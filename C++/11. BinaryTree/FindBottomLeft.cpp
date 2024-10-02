/*
                -> Find Bottom Left Tree Value <-

Given the root of a binary tree, return the leftmost value in the last row of the tree.

    Example 1:
    Input: root = [2,1,3]
    Output: 1
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
    int findBottomLeftValue(TreeNode* root) {
        map<int, map<int, int> > treeNode;
        queue<pair<TreeNode*, pair<int,int> > > q;
        
        q.push(make_pair(root, make_pair(0, 0) ) );
        int ans = 0;
        int maxLevel = 0;
        
        while (!q.empty()) {
            pair<TreeNode*, pair<int,int> > temp = q.front();
            q.pop();
            
            TreeNode* node = temp.first;
            int hd = temp.second.first;
            int lvl = temp.second.second;
            
            maxLevel = max(maxLevel, lvl);
            
            treeNode[lvl][hd] = node->val;
            
            if (node->left) {
                q.push(make_pair(node->left, make_pair(hd-1, lvl+1) ) );
            }
            
            if (node->right) {
                q.push(make_pair(node->right, make_pair(hd+1, lvl+1) ) );
            }
            
        }   
        
        int mostLeft = INT_MAX;
        
        for (auto i: treeNode) {
            if (i.first == maxLevel) {
                for (auto j: i.second) {
                    if (j.first < mostLeft) {
                        mostLeft = j.first;
                        ans = j.second;
                    }
                }
            }
        }
        
        return ans;
    }
};