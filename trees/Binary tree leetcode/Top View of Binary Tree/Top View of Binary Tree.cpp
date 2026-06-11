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
    vector<int> topView(TreeNode* root){
        vector<int> ans;
        if(root==NULL){
            return ans;
        }
        map<int,int> mp;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        while(!q.empty()){
            pair<TreeNode*,int> temp=q.front();
            q.pop();
            TreeNode* node=temp.first;
            int hd=temp.second;
            if(mp.find(hd)==mp.end()){ ////doubt
                mp[hd]=node->val;
            }
            if(node->left){
                q.push({node->left,hd-1});
            }
            if(node->right){
                q.push({node->right,hd+1});
            }
        }
        for(auto it:mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};