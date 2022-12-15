/*
                -> Construct Binary Tree from Preorder and Inorder Traversal <-

Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.

    Example 1:
    Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
    Output: [3,9,20,null,null,15,7]
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
    void createMapping(vector<int> &inOrder, map<int, int> &nodeToIndex, int n) {
        for (int i = 0; i < n; i++) {
            nodeToIndex[inOrder[i]] = i;
        }
    }

    TreeNode* solve(vector<int> &pre, int &index, int inStart, int inEnd, map<int, int> &nodeToIndex, int n) {
        if (index >= n || inStart > inEnd) {
            return NULL;
        }

        int element = pre[index++];
        TreeNode* root = new TreeNode(element);
        int position = nodeToIndex[element];

        root->left = solve(pre, index, inStart, position-1, nodeToIndex, n);
        root->right = solve(pre, index, position+1, inEnd, nodeToIndex, n);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preIndex = 0;
        map<int, int> nodeToIndex;
        int size = inorder.size();
        createMapping(inorder, nodeToIndex, size);
        TreeNode* ans = solve(preorder, preIndex, 0, size-1, nodeToIndex, size);
        return ans;
    }
};