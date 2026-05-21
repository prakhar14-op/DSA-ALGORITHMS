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

Node* delete_head(Node* head){
    if(head==NULL){
        return NULL;
    }
    Node* prev=head;
    head=head->next;
    if(head!=NULL){
        head->prev=NULL;
    }
    prev->next=NULL;
    delete prev;
    return head;
}

Node* delete_tail(Node* head){
    if(head==NULL){
        return NULL;
    }
    Node* tail=head;
    while(tail->next!=NULL){
        tail=tail->next;
    }
    Node* prev=tail->prev;
    prev->next=NULL;
    tail->prev=NULL;
    delete tail;
    return head;
}


Node* delete_kth_node(Node* head,int k){
    if(head==NULL){
        return NULL;
    }
    if(k==1){
        return delete_head(head);
    }
    Node* temp=head;
    for(int i=1;i<k && temp!=NULL;i++){
        temp=temp->next;
    }
    if(temp==NULL){
        return head;
    }
    if(temp->next==NULL){
        return delete_tail(head);
    }
    Node* prev=temp->prev;
    Node* next=temp->next;
    prev->next=next;
    next->prev=prev;
    temp->prev=NULL;
    temp->next=NULL;
    delete temp;
    return head;
}
Node* delete_node(Node* head,int key){
    if(head==NULL){
        return NULL;
    }
    //case 1 deleting head node
    if(head->data==key){
        return delete_head(head);
    }
    Node* temp=head;
    while(temp!=NULL && temp->data!=key){
        temp=temp->next;
    }
    //case 2 key not found
    if(temp==NULL){
        return head;
    }
    //case 3 deleting tail node
    if(temp->next==NULL){
        return delete_tail(head);
    }
    Node* prev=temp->prev;
    Node* next=temp->next;
    prev->next=next;
    next->prev=prev;
    temp->prev=NULL;
    temp->next=NULL;
    delete temp;
    return head;
}


int main(){
    vector<int> arr={12,5,8,7};
    Node* head=arr_to_dll(arr);
    cout<<"The DLL is: ";
    print(head);
    head=delete_head(head);
    cout<<"The DLL after deleting head is: ";
    print(head);
    cout<<"The DLL after deleting tail is: ";
    head=delete_tail(head);
    print(head);
    cout<<"The DLL after deleting node with value 8 is: ";
    head=delete_node(head,8);
    print(head);
    return 0;
}