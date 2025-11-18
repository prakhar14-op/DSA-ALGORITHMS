#include<iostream>
using namespace std;

struct node 
{   int data;
    struct node *next;
}*first=NULL;


void create(int A[], int n)
{
    int i;
    struct node *t,*last;
    first= new node;
    first->data=A[0];
    first->next=NULL;
    last=first; 

    for(i=1; i<n;i++){
        t=new node;
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}


int sum(struct node *p){
    int sum=0;
    while(p!=0){
        sum=sum+p->data;
        p=p->next;
    }
    return sum;
}

int count(struct node *p){
    int count=0;
    while(p!=0){
        count++;
        p=p->next;
    }
    return count;
}

void display(struct node *p){
    while(p!=0){
        cout<<  p->data<<"->";
        p=p->next;
    }
}

void insert(int pos,int key){
    node *t,*p;
    if(pos==0){
        t=new node;
        t->data=key;
        t->next=first;
        first=t;
    }
    else if(pos>0){
        p=first;
        for(int i=0;i<pos-1;i++){
            p=p->next;
        }
        if(p){
            t=new node;
            t->data=key;
            t->next=p->next;
            p->next=t;
        }
    }
}

int main(){
    int A[]={3,5,6,7};
    create(A,4);
    display(first);
    cout<<'\n';
    cout<<"sum is :";
    cout<<sum(first); 
    cout<<"\n";
    cout<<"number of nodes :";
    cout<<count(first);
    cout<<'\n';
    cout<<"key you want to insert :";
    int key;
    cin>>key;
    insert(3,key);
    display(first);
}

