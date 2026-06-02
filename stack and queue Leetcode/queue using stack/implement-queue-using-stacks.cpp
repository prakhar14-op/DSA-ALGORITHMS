#include<bits/stdc++.h>
using namespace std;
class MyQueue {
private:
    stack<int> s1,s2;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        if(!s2.empty()){
            int removeele=s2.top();
            s2.pop();
            return removeele;
        }
        else{
            //s1->s2
            while(s1.size()){
                s2.push(s1.top());
                s1.pop();
            }
            int removeele=s2.top();
            s2.pop();
            return removeele;
        }
    }
    
    int peek() {
        if(!s2.empty()){
            return s2.top();
        }
        else{
            while(s1.size()){
                s2.push(s1.top());
                s1.pop();
            }
            return s2.top();
        }
    }

    
    bool empty() {
        return s1.empty() && s2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */