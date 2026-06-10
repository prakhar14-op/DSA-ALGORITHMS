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
//approach 1
class Solution {
private:
    int maxDepth(TreeNode* root) {
        TreeNode* node=root;
        if(node==NULL){
            return 0;
        }
        int left=maxDepth(node->left);
        int right=maxDepth(node->right);
        int ans=max(left,right)+1;
        return ans; 
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        TreeNode* temp=root;
        if(temp==NULL){
            return 0;
        }
        int op1=diameterOfBinaryTree(temp->left);
        int op2=diameterOfBinaryTree(temp->right);
        int op3=maxDepth(temp->left)+maxDepth(temp->right);
        int ans=max(op1,max(op2,op3));
        return ans;
    }
};
//approach 2
class Solution {
private:
    pair<int,int> diameterfast(TreeNode* node){
        //base case
        if(node==NULL){
            pair<int,int> p=make_pair(0,0);
            return p;
        }
        pair<int,int> left=diameterfast(node->left);
        pair<int,int> right=diameterfast(node->right);

        int op1=left.first;
        int op2=right.first;
        int op3=left.second+right.second;
        pair<int,int> ans;
        ans.first=max(op1,max(op2,op3));
        ans.second=max(left.second,right.second)+1;
        return ans;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        TreeNode* temp=root;
        return diameterfast(temp).first;
    }
};