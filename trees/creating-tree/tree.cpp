#include<iostream>
using namespace std;

struct node{
    node *lchild;
    int data;
    node *rchild;
};

struct queue{
    int front;
    int rear;
    int size;
    node **Q;
};

void createQueue(struct queue *q, int size){
    q->size = size;
    q->front = 0; // Or -1, depending on implementation style. Using 0 for simplicity.
    q->rear = 0;
    q->Q=new node*[q->size]; 
}

void enqueue(struct queue *q,struct node *key){
    if(q->rear==q->size-1){
        cout<<"queue is full";
    }
    else{
        q->rear++;
        q->Q[q->rear]=key;// store the address of root in the queue 
    }
    cout<<'\n'; 
}

struct node *dequeue(struct queue *q){
    struct node *x = NULL;
    if(q->front==q->rear){
        cout<<"queue is empty";
    }
    else{
        q->front++;
        x=q->Q[q->front];
    }
    return x;
}

int isEmpty(struct queue q){
 return q.front==q.rear;
}

struct node *root=NULL; // root pointer which is pointing to a node struct which is null right now 

void treecreate(){
    struct node *p,*t;
    int x;
    struct queue q;
    createQueue(&q,100);
    
    cout<<"enter the root value ";
    cin>>x;
    root =new node; // made a root node in heap
    root->data=x;
    root->lchild=root->rchild=NULL;

    enqueue(&q,root);// it will add the address of the root node in the queue 

    while(!isEmpty(q)){
        int y;
        p=dequeue(&q);
        cout<<"enter the left child "<<" -1 for no node ";
        cin>>y;
        if(y!=-1){
            t = new node;
            t->data=y;
            t->lchild=t->rchild=NULL;
            p->lchild=t;
            enqueue(&q,t);
            
        }
        int z;
        cout<<"enter the value for right child ";
        cin>>z;
        if(z!=-1){
            t = new node;
            t->data=z;
            t->lchild=t->rchild=NULL;
            p->rchild=t;
            enqueue(&q,t);
        }
    }
}

void preorder(struct node *p){
    if(p){
        cout<<p->data;
        preorder(p->lchild);
        preorder(p->rchild);
    }
}

void postorder(struct node *p){
    if(p){
        postorder(p->lchild);
        postorder(p->rchild);
        cout<<p->data;
    }
}
void inorder(struct node *p){
    if(p){
        inorder(p->lchild);
        cout<<p->data;
        inorder(p->rchild);
    }
}


int main(){
    treecreate();
    postorder(root);
}

