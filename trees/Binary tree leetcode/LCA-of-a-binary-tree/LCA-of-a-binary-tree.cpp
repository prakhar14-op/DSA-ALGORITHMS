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
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* temp=root;
        if(temp==NULL){
            return NULL;
        }
        if(temp==p || temp==q){
            return temp;
        }
        TreeNode* leftans=lowestCommonAncestor(temp->left,p,q);
        TreeNode* rightans=lowestCommonAncestor(temp->right,p,q);
        if(leftans!=NULL && rightans!=NULL){
            return temp;
        }
        else if(leftans!=NULL && rightans==NULL){
            return leftans;
        }
        else if(leftans==NULL && rightans!=NULL){
            return rightans;
        }
        else{
            return NULL;
        }
    }
}; 