#include <bits/stdc++.h>
using namespace std;
#include <vector>
#include <iostream>
class Node{
    public:
    int data;
    Node* prev;
    Node* next;
    Node(int val){
        data=val;
        prev=NULL;
        next=NULL;
    }
    Node(int val,Node* prev1,Node* next1){
        data=val;
        prev=prev1;
        next=next1;
    }
};
Node* arr_to_dll(vector<int> arr){
    if(arr.size()==0){
        return NULL;
    }
    Node* head=new Node(arr[0]);
    Node* prev=head;
    for(int i=1;i<arr.size();i++){
        Node* newnode=new Node(arr[i]);
        prev->next=newnode;
        newnode->prev=prev;
        prev=prev->next;
    }
    return head;
}
Node* print(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
Node* insert_at_head(Node* head,int key){
    Node* newhead=new Node(key);
    if(head==NULL){
        return newhead;
    }
    newhead->next=head;
    head->prev=newhead;
    return newhead; 
}

Node* insert_before_tail(Node* head,int key){
    if(head==NULL){
        return NULL;
    }
    Node* tail=head;
    while(tail->next!=NULL){
        tail=tail->next;
    }
    Node* prev=tail->prev;
    Node* newnode=new Node(key,tail,prev);
    prev->next=newnode;
    tail->prev=newnode;
    return head;
}

Node* insert_before_kth_node(Node* head,int key,int k){
    if(head==NULL){
        return NULL;
    }
    Node* temp=head;
    for(int i=1;i<k && temp!=NULL;i++){
        temp=temp->next;
    }
    if(temp==NULL){
        return head;
    }
    Node* prev=temp->prev;
    Node* newnode=new Node(key,temp,prev);
    prev->next=newnode;
    temp->prev=newnode;
    return head;
}

int main(){
    vector<int> arr={12,5,8,7};
    Node* head=arr_to_dll(arr);
    cout<<"The DLL is: ";
    print(head);
    int key=10;
    head=insert_at_head(head,key);
    cout<<"After inserting "<<key<<" at head the DLL is: ";
    print(head);
    key=15;
    head=insert_before_tail(head,key);
    cout<<"After inserting "<<key<<" before tail the DLL is: ";
    print(head);
    key=20;
    int k=3;
    head=insert_before_kth_node(head,key,k);
    cout<<"After inserting "<<key<<" before "<<k<<"th node the DLL is: ";
    print(head);
    return 0;
}