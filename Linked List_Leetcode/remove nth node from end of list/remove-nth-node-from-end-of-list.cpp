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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp=head;
        //finding the length of the linked list
        int count=0;
        while(temp!=NULL){
            count++;
            temp=temp->next;
        }
        if(count==n){
            free(head); //freeing the memory of the head node
            return head->next;
        }
        temp=head;
        for(int i=1;i<count-n;i++){
            temp=temp->next;
        }
        temp->next=temp->next->next;
        return head;
    } 
};
//optimized approach
class Solution {
public:    
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast=head;
        ListNode* slow=head;
        for(int i=0;i<n;i++){
            fast=fast->next;
        }
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next;
        }
        ListNode* delnode=slow->next;
        slow->next=slow->next->next;
        return head;
    }
};