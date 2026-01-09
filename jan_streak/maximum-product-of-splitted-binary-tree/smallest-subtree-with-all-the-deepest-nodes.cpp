/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include<iostream>
#include<vector>
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
    pair<int, TreeNode*> dfs(TreeNode* root) {
        // base case
        if (root == nullptr)
            return {0, nullptr};

        // recurse on left and right
        auto left = dfs(root->left);
        auto right = dfs(root->right);

        // if left subtree is deeper
        if (left.first > right.first) {
            return {left.first + 1, left.second};
        }

        // if right subtree is deeper
        if (right.first > left.first) {
            return {right.first + 1, right.second};
        }

   
        return {left.first + 1, root};
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return dfs(root).second;
    }

};
