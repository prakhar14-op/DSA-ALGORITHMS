#include<bits/stdc++.h>
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    void preorder(TreeNode* node,vector<vector<int>>& adj){
        //base case 
        if(node==NULL){
            return;
        }
        if(node->left!=nullptr){
            adj[node->val].push_back(node->left->val);
            adj[node->left->val].push_back(node->val);
            preorder(node->left,adj);
        }
        if(node->right!=nullptr){
            adj[node->val].push_back(node->right->val);
            adj[node->right->val].push_back(node->val);
            preorder(node->right,adj);
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        //making the adj list from the given tree
        //we wil traverse the tree using the preorder and make the adj list simultaiously
        vector<vector<int>> adj(501);//since number of nodes can be in the range of[1,500]
        preorder(root,adj);

        //now our tree is converted to graph (bidirectional)
        queue<int> q;
        vector<bool> vis(501,false);
        vector<int> result;
        q.push(target->val);
        vis[target->val]=true;
        int current_step=0;
        while(!q.empty()){
            if(current_step==k){
                //now we have only those nodes havingg the kth distance from target
                while(!q.empty()){
                    result.push_back(q.front());
                    q.pop();
                }
                return result;
            }
            //visiting the neighbour 
            // at a time the queue will only contain the nodes with a specific distance from the target 'A'
            int size=q.size();
            for(int i=0;i<size;i++){
                int f=q.front();
                q.pop();
                //going to trraverse the neighbours
                for(int it:adj[f]){
                    if(!vis[it]){
                        vis[it]=true;
                        q.push(it);
                    }
                }
            }
            //adding the nodes layer by layer using the bfs
            //now inc the distnce 
            current_step++;
        }
        return result;

    }
};