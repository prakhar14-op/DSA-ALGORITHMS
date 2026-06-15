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
    void flatten(TreeNode* root) {
        TreeNode* current= root;
        while(current!=NULL){
            if(current->left){
                TreeNode* prev=current->left;
                while(prev->right){
                    prev=prev->right ;               
                }
                prev->right=current->right;
                current->right=current->left;
            }
            current=current->right; 
        }
        //left pointer ko null karte jao 
        current=root;
        while(current!=NULL){
            current->left=NULL;
            current=current->right;
        }
    }
};