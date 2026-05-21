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

int main(){
    vector<int> arr={12,5,8,7};
    Node* head=arr_to_dll(arr);
    cout<<"The DLL is: ";
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    return 0;
}