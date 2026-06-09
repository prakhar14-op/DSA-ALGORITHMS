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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<int> current;
        vector<vector<int>> result;
        if(root==NULL){
            return result;
        }
        
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            TreeNode* temp=q.front();
            q.pop();
            if(temp==NULL){
                result.push_back(current);
                current.clear();
                // 1. What do we do with the 'current' buffer?
                // 2. How do we prepare the buffer for the next level?
                // 3. How do we safely push the next NULL without causing an infinite loop?
                if(!q.empty()){
                    q.push(NULL);
                }

            }
            else{
                current.push_back(temp->val);
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
        }
        return result;

    }
};