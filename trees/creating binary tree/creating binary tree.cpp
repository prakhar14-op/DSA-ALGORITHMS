#include<bits/stdc++.h>
using namespace std;
class node{
    public:
        node *lchild;
        int data;
        node *rchild;
    node(int val){
        data=val;
        lchild=rchild=NULL;
    }
};
node *buildtree(node *root){
    cout<<"enter the value for the node ";
    int val;
    cin>>val;
    if(val==-1){
        return NULL;
    }
    root=new node(val);
    cout<<"enter the value for left child of "<<val<<endl;
    root->lchild=buildtree(root->lchild);
    cout<<"enter the value for right child of "<<val<<endl;
    root->rchild=buildtree(root->rchild);
    return root;
}

void levelorder(node *root){
    queue<node*> q;
     node *p;
     node *t;
    if(root==NULL){
        return;
    }
    q.push(root);
    while(!q.empty()){
        p=q.front();
        q.pop();
        cout<<p->data<<" ";
        if(p==NULL){
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            if(p->lchild){
            q.push(p->lchild);
            }
            if(p->rchild){
                q.push(p->rchild);
            }
        }
        
    }
}

void inorder(node* root){
    node* temp=root;
    if(temp==NULL){
        return;
    }
    inorder(temp->lchild);
    cout<<temp->data<<" ";
    inorder(temp->rchild);
}
void preorder(node* root){
    node* temp=root;
    if(temp==NULL){
        return;
    }
    cout<<temp->data<<" ";
    preorder(temp->lchild);
    preorder(temp->rchild);
}

void postorder(node* root){
    node* temp=root;
    if(temp==NULL){
        return;
    }
    postorder(temp->lchild);
    postorder(temp->rchild);
    cout<<temp->data<<" ";
}

void buildtreelevelorder(node *root){
    queue<node*> q;
    cout<<"enter data fro root node ";
    int data;
    cin>>data;
    root=new node(data);
    q.push(root);
    while(!q.empty()){
        node *temp=q.front();
        q.pop();
        cout<<"enter the value for left child of "<<temp->data<<" -1 for no node " <<endl;
        int leftdata;
        cin>>leftdata;
        if(leftdata!=-1){
            temp->lchild=new node(leftdata);
            q.push(temp->lchild);
        }
        cout<<"enter the value for right child of "<<temp->data<<" -1 for no node " <<endl;
        int rightdata;
        cin>>rightdata;
        if(rightdata!=-1){
            temp->rchild=new node(rightdata);
            q.push(temp->rchild);
        }
    }
}
int main(){
    node *root=NULL;
    root=buildtree(root);
    cout<<"the level order traversal is "<<endl;
    levelorder(root);
    cout<<endl<<"the inorder traversal is "<<endl;
    inorder(root);
    cout<<endl<<"the preorder traversal is "<<endl;
    preorder(root);
    cout<<endl<<"the postorder traversal is "<<endl;
    postorder(root);
    return 0;
}