#include<bits/stdc++.h>
using namespace std;
struct Node {
    int val;
    Node *next;
    Node() : val(0), next(nullptr) {}
    Node(int x) : val(x), next(nullptr) {}
    Node(int x, Node *next) : val(x), next(next) {}
};
class MinStack {
private:
    stack<int> st;
    Node* topp;
    stack<int> min_st;
public:
    MinStack() {
        topp=nullptr;
    }
    int size=0;
    
    void push(int val) {
        Node* temp=new Node(val, topp);
        topp=temp;
        if (min_st.empty() || val <= min_st.top()) {
            min_st.push(val);
        }
        size=size+1;
    }
    
    void pop() {
        if (topp == nullptr) return;
        if (topp->val == min_st.top()) {
            min_st.pop();
        }
        Node* temp=topp;
        topp=topp->next;
        delete temp;
        size=size-1;
    }
    
    int top() {
        if (topp == nullptr) return -1;
        return topp->val;
    }
    
    int getMin() {
        if (min_st.empty()) return -1;
        return min_st.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */