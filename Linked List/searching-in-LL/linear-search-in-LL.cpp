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

node* linear_search(struct node *p,int key){
    while(p!=NULL){
        if(key==p->data){
            return p;
        }
        else{
            p=p->next;
        }
    }
    return NULL;
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
    node *search_result=linear_search(first,6);
    cout<<search_result;
}