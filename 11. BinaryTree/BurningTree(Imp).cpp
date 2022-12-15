/*
                -> Burining Tree (Simillar) (Imp) <-

Given the root of a binary tree, the value of a target node target, and an integer k, return an array of the values of all nodes that have a distance k from the target node.

You can return the answer in any order.

    Example 1:
    Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2
    Output: [7,4,1]
    Explanation: The nodes that are a distance 2 from the target node (with value 5) have values 7, 4, and 1.
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
    TreeNode* createMappingList(TreeNode* root, int target, map<TreeNode*, TreeNode*> &nodeToParent) {
        TreeNode* targetNode = NULL;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            TreeNode* front = q.front();
            q.pop();

            if (front->val == target) {
                targetNode = front;
            }

            if (front->left) {
                nodeToParent[front->left] = front;
                q.push(front->left);
            }

            if (front->right) {
                nodeToParent[front->right] = front;
                q.push(front->right);
            }
        }

        return targetNode;
    }

    void solve(TreeNode* root, int k, map<TreeNode*, TreeNode*> &nodeToParent, vector<int> &ans) {
        map<TreeNode*, bool> visited;
        queue<TreeNode*> q;

        q.push(root);
        visited[root] = true;

        while(!q.empty()) {
            bool flag = false;
            int size = q.size();
            
            if (k <= 0) break;

            for (int i = 0; i < size; i++) {
                TreeNode* front = q.front();
                q.pop();

                if (front->left && !visited[front->left]) {
                    flag = true;
                    visited[front->left] = true;
                    q.push(front->left);
                }

                if (front->right && !visited[front->right]) {
                    flag = true;
                    visited[front->right] = true;
                    q.push(front->right);
                }

                TreeNode* parent = nodeToParent[front];
                if (parent && !visited[parent]) {
                    flag = true;
                    visited[parent] = true;
                    q.push(parent);
                }
            }

            if (flag) {
                k--;
            }
        }

        while(!q.empty()) {
            TreeNode* front = q.front();
            q.pop();
            ans.push_back(front->val);
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        map<TreeNode*, TreeNode*> nodeToParent;

        TreeNode* targetNode = createMappingList(root, target->val, nodeToParent);

        solve(targetNode, k, nodeToParent, ans);

        return ans;
    }
};