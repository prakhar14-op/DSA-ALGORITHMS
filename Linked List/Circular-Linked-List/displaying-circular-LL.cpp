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