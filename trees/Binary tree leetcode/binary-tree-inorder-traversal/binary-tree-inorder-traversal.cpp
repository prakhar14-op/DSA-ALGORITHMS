#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
private: 
    void traverse(TreeNode* node,vector<int>& ans){
        TreeNode* temp=node;
        if(temp==NULL){
            return;
        }
        traverse(temp->left,ans);
        ans.push_back(temp->val);
        traverse(temp->right,ans);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        traverse(root,ans);
        return ans;
    }
};