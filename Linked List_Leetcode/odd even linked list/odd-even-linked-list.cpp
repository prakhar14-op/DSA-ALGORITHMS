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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* temp=head;
        vector<int> arr;
        if(head==NULL || head->next==NULL){
            return head;
        }
        while(temp!=NULL && temp->next!=NULL){
            arr.push_back(temp->val);
            temp=temp->next->next;
        }
        if(temp) arr.push_back(temp->val); 
        temp=head->next;
        while(temp!=NULL && temp->next!=NULL){
            arr.push_back(temp->val);
            temp=temp->next->next;
        }
        if(temp) arr.push_back(temp->val);
        int i=0;
        temp=head;
        while(temp!=NULL){
            temp->val=arr[i];
            i++;
            temp=temp->next;
        }
        return head;
    }
};

//mt 2
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode* odd=head;
        ListNode* even= head->next;
        ListNode* even_head=head->next;
        while(even!=NULL && even->next!=NULL){
            odd->next=odd->next->next;
            even->next=even->next->next;

            odd=odd->next;
            even=even->next;
        }
        odd->next=even_head;
        return head;
    }
};