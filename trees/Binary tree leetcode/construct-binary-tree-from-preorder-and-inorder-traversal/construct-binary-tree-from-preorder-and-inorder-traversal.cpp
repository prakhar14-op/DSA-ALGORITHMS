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
    int findposition(vector<int>& in,int element,int n){
        for(int i=0;i<n;i++){
            if(in[i]==element){
                return i;
            }
        }
        return -1;
    }
    TreeNode* solve(vector<int>& in,vector<int>& pre, int &index,int inorderstart, int inorderend,int n){
        if(index>=n || inorderstart>inorderend){
            return NULL;
        }
        int element=pre[index++];
        TreeNode* temp=new TreeNode(element);
        int position=findposition(in,element,n);
        //recusrive call
        temp->left=solve(in,pre, index,inorderstart,position-1,n);
        temp->right=solve(in,pre, index,position+1,inorderend,n);
        return temp;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preorderindex=0;
        int n=inorder.size();
        TreeNode* ans=solve(inorder,preorder,preorderindex,0,n-1,n);
        return ans;
    }
};