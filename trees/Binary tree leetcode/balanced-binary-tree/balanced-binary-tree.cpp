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
//brute force
class Solution {
private:
    int height(TreeNode* root) {
        TreeNode* node=root;
        if(node==NULL){
            return 0;
        }
        int left=height(node->left);
        int right=height(node->right);
        int ans=max(left,right)+1;
        return ans; 
    }
public:
    bool isBalanced(TreeNode* root) {
        if(root==NULL){
            return true;
        }
        bool left=isBalanced(root->left);
        bool right=isBalanced(root->right);
        bool diff=abs(height(root->left)-height(root->right))<=1;
        if(left && right && diff){
            return true;
        }
        else{
            return false;
        }
    }
};

//optimal approach
class Solution {
private:
    pair<bool,int> isBalancedfast(TreeNode* node){
        //base case
        if(node==NULL){
            pair<bool,int> p=make_pair(true,0);
            return p;
        }
        pair<bool,int> left=isBalancedfast(node->left);
        pair<bool,int> right=isBalancedfast(node->right);

        bool leftans=left.first;
        bool rightans=right.first;
        bool diff=abs(left.second-right.second)<=1;

        pair<bool,int> ans;
        ans.second=max(left.second,right.second)+1;
        if(leftans && rightans && diff){
            ans.first=true;
        }
        else{
            ans.first=false;
        }
        return ans;

    }
public:
    bool isBalanced(TreeNode* root) {
        return isBalancedfast(root).first;
    }
};