#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    stack<char> st;
public:
    bool isValid(string s) {
        for(char i:s){
            if(i=='(' || i=='[' || i=='{'){
                st.push(i);
            }
            else if(i==')'){
                if(!st.empty() && st.top()=='('){
                    st.pop();
                }
                else{
                    return false;
                }
            }
            else if(i==']'){
                if(!st.empty() && st.top()=='['){
                    st.pop();
                }
                else{
                    return false;
                }
            }
            else if(i=='}'){
                if(!st.empty() && st.top()=='{'){
                    st.pop();
                }
                else{
                    return false;
                }
            }
        }
        if(st.empty()){
            return true;
        }
        return false;
    }
};