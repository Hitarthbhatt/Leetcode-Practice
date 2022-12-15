/*
                -> Construct Binary Tree from Inorder and Postorder Traversal <-

Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree, construct and return the binary tree.

    Example 1:
    Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
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

    TreeNode* solve(vector<int> &pos, int &index, int inStart, int inEnd, map<int, int> &nodeToIndex, int n) {
        if (index < 0 || inStart > inEnd) {
            return NULL;
        }

        int element = pos[index--];
        TreeNode* root = new TreeNode(element);
        int position = nodeToIndex[element];

        // Postorder LRN
        root->right = solve(pos, index, position+1, inEnd, nodeToIndex, n);
        root->left = solve(pos, index, inStart, position-1, nodeToIndex, n);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int, int> nodeToIndex;
        int size = inorder.size();
        int postIndex = size - 1;
        createMapping(inorder, nodeToIndex, size);
        TreeNode* ans = solve(postorder, postIndex, 0, size-1, nodeToIndex, size);
        return ans;
    }
};