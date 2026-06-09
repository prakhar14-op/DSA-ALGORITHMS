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
};