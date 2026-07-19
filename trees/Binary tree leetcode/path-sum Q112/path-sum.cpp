#include<bits/stdc++.h>
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
    bool hasPathSum(TreeNode* root, int targetsum) {
        // base cases
        if(root==NULL){
            return false;
        }
        if(root->left==NULL && root->right==NULL){
            if (root->val==targetsum){
                return true;
            }
            else{
                return false;
            }
        }
        int remaining_sum=targetsum-root->val;
        return (hasPathSum(root->left,remaining_sum) || hasPathSum(root->right,remaining_sum));

    }
};