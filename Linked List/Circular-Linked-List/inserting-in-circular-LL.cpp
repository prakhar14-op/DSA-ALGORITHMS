#include<iostream>
using namespace std;

struct node{
    int data;
    struct node *next;
}*first=NULL;

void display(struct node *p){
    do{
        cout<<p->data;
        p=p->next;
    }while(p!=first);
    
}

void insert(int pos ,int key){
    struct node *t,*p;
    int i;
    if(pos==0){
        t=new node;
        t->data=key;
        if(first=NULL){
            first=t;
            first->next=first;
        }
        else{
            p=first;
            while(p->next!=first){
                p=p->next;
            }
            p->next=t;
            t->next=first;
            first=t;
        }
    }
    else{
        struct node *t;
        struct node *p=first;
        for(i=0;i<pos-1;i++){
            p=p->next;
        }
        t=new node;
        t->data=key;
        t->next=p->next;
        p->next=t;
    }

}