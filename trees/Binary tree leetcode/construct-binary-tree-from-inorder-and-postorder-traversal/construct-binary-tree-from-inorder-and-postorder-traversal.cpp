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
private: 
    void createmapping(vector<int>& in,map<int,int> &nodetoindex ,int n){
        for(int i=0;i<n;i++){
            nodetoindex[in[i]]=i;
        }
        
    }
    TreeNode* solve(vector<int>& in,vector<int>& post, int &index,int inorderstart, int inorderend,int n,map<int,int> &nodetoindex){
        if(index<0 || inorderstart>inorderend){
            return NULL;
        }
        //taking the last elemnt form the post order and making it the root 
        int element=post[index--];
        TreeNode* temp=new TreeNode(element);
        //finding that elemet in inorder 
        int position=nodetoindex[element];
        //recusrive call
        temp->right=solve(in,post, index,position+1,inorderend,n,nodetoindex);
        temp->left=solve(in,post, index,inorderstart,position-1,n,nodetoindex);
        
        return temp;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=inorder.size();
        int postorderindex=n-1;
        map<int,int> nodetoindex;
        //creating the map 
        createmapping(inorder,nodetoindex,n);
        TreeNode* ans=solve(inorder,postorder,postorderindex,0,n-1,n,nodetoindex);
        return ans;
    }
};