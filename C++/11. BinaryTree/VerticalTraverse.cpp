/*
            -> Vertical Order Traversal of a Binary Tree (Hard) <-

Given the root of a binary tree, calculate the vertical order traversal of the binary tree.

For each node at position (row, col), its left and right children will be at positions (row + 1, col - 1) and (row + 1, col + 1) respectively. The root of the tree is at (0, 0).

The vertical order traversal of a binary tree is a list of top-to-bottom orderings for each column index starting from the leftmost column and ending on the rightmost column. There may be multiple nodes in the same row and same column. In such a case, sort these nodes by their values.

Return the vertical order traversal of the binary tree.

    Example 1:
    Input: root = [3,9,20,null,null,15,7]
    Output: [[9],[3,15],[20],[7]]
    Explanation:
    Column -1: Only node 9 is in this column.
    Column 0: Nodes 3 and 15 are in this column in that order from top to bottom.
    Column 1: Only node 20 is in this column.
    Column 2: Only node 7 is in this column.

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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, vector<int> > > nodes;
        queue<pair<TreeNode*, pair<int, int> > > q;
        vector<vector<int>> ans;
        
        if (root == NULL) return ans;
        q.push(make_pair(root, make_pair(0, 0)));
        
        while (!q.empty()) {
            pair<TreeNode*, pair<int, int> > temp = q.front();
            q.pop();
            int hd = temp.second.first;
            int lvl = temp.second.second;
            
            TreeNode* node = temp.first;
            nodes[hd][lvl].push_back(node -> val);
            
            if (node -> left) {
                q.push(make_pair(node -> left, make_pair(hd - 1, lvl + 1)));
            }
            
            if (node -> right) {
                q.push(make_pair(node -> right, make_pair(hd + 1, lvl + 1)));
            }
        }
        
        for (auto i: nodes) {
            vector<int> output;
            for(auto j: i.second) {
                vector<int> temp;
                for(auto k: j.second) {
                    temp.push_back(k);
                }
                sort(temp.begin(), temp.end());   
                output.insert(output.end(), temp.begin(), temp.end());
            }
            ans.push_back(output);
        }
        
        return ans;
    }
};