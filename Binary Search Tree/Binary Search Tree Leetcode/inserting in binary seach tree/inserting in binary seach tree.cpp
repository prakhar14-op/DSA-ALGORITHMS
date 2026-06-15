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
class solution{
    public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* temp=root;
        TreeNode* newnode=new TreeNode(val);
        if(temp==NULL){
            return newnode;
        }
        while(temp!=NULL){
            if(temp->val>val){
                //moving left
                if(temp->left==NULL){
                    temp->left=newnode;
                    return root;
                }
                temp=temp->left;
            }
            else{
                //moving right
                if(temp->right==NULL){
                    temp->right=newnode;
                    return root;
                }
                temp=temp->right;
            }
        }
        return root;
    }
};