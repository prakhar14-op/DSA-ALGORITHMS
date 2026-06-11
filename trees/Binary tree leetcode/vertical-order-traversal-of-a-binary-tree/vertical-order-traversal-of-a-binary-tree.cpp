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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>> nodes;
        queue<pair<TreeNode*,pair<int,int>>> q;
        
        vector<vector<int>> result;
        if(root==NULL){
            return result;
        }
        q.push(make_pair(root,make_pair(0,0)));
        while(!q.empty()){
            //taking q ka front 
            pair<TreeNode*,pair<int,int>> temp=q.front();
            q.pop();
            //extracting the data to put in the map 
            TreeNode* frontnode=temp.first;
            int hd=temp.second.first;
            int lvl=temp.second.second;
            //putting the data in the map
            nodes[hd][lvl].insert(frontnode->val);
            if(frontnode->left){
                q.push(make_pair(frontnode->left,make_pair(hd-1,lvl+1)));
            }
            if(frontnode->right){
                q.push(make_pair(frontnode->right,make_pair(hd+1,lvl+1)));
            }
        }
        for(auto line:nodes){
            vector<int> ans;
            for(auto level:line.second){
                for(auto value:level.second){
                    ans.push_back(value);
                }
            }
            result.push_back(ans);
        }
        return result;
    }
};