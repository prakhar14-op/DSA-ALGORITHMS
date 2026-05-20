#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        //brute force approach
        vector<int> arr;
        ListNode* temp=head;
        int i=0;
        while(temp!=NULL){
            arr.push_back(temp->val);
            i++;
            temp=temp->next;
        }
        //now arranging all the elments in the vector in ascending order 
        sort(arr.begin(),arr.end());
        //now just placing them back in the linked list
        temp=head;
        int j=0;
        while(temp!=NULL){
            temp->val=arr[j];
            j++;
            temp=temp->next;
        }
        return head;
    }
};
//optimal approach
class Solution {
public:
    ListNode*findmiddle(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode* merge(ListNode* left,ListNode* right){
        ListNode* dummy_node=new ListNode(-1);
        ListNode* temp=dummy_node;
        while(left!=NULL && right!=NULL){
            if(left->val<right->val){
                temp->next=left;
                temp=temp->next;
                left=left->next;
            }
            else{
                temp->next=right;
                temp=temp->next;
                right=right->next;
            }
        }
        while(left!=NULL){
            temp->next=left;
            temp=temp->next;
            left=left->next;
        }
        while(right!=NULL){
            temp->next=right;
            temp=temp->next;
            right=right->next;
        }
        return dummy_node->next;
    }
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* middle=findmiddle(head);
        ListNode* left=head;
        ListNode* right=middle->next;
        middle->next=NULL;
        left=sortList(left);
        right=sortList(right);
        return merge(left,right);
    }
};