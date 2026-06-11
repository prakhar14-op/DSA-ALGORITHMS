#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root==NULL){
            return result;
        }
        queue<TreeNode*> q;
        q.push(root);
        bool lefttoright=true;
        while(!q.empty()){
            
            int size=q.size();
            vector<int> ans(size);
            for(int i=0;i<size;i++){
                TreeNode* front=q.front();
                q.pop();
                int index=lefttoright? i:size-1-i;
                ans[index]=front->val;
                if(front->left){
                    q.push(front->left);
                }
                if(front->right){
                    q.push(front->right);
                }
                
                
            }
            lefttoright=!lefttoright;
            result.push_back(ans);
        }
        return result;
    }
};