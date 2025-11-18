#include<iostream>
using namespace std;


struct Node{
    struct Node *lchild;
    int data;
    struct Node *rchild;

}*root=NULL;

void insert(int key){
    struct Node *t=root;
    struct Node *r,*p;

    if (root ==NULL){
        p=new Node;
        p->data=key;
        p->lchild=p->rchild=NULL;
        root=p;
        return;
    }
    while(t!=NULL){
        r=t;
        if(key<t->data){
            t=t->lchild;
        }
        else if(key>t->data){
            t=t->rchild;
        }
        else{
            return;
        }
    }
    p=new Node;
    p->data=key;
    p->lchild=p->rchild=NULL;

    if(key<r->data) r->lchild=p;
    else r->rchild=p;

}

void inorder(struct Node *p){
    if (p){
        inorder(p->lchild);
        cout<<p->data<<" ";
        inorder(p->rchild);
    }
}

int main(){
    insert(10);
    insert(5);
    insert(15);
    insert(20);
    insert(12);
    insert(16);
    inorder(root);
    cout<<'\n';
}