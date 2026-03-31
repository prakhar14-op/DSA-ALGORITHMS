#include<iostream>
using namespace std;
class Solution {
public:
    string removeOuterParentheses(string s) {
        int balance=0;
        string result="";
        for(char c:s){
            if(c=='('){
                //if balance >0 means vo inner vla hai 
                if(balance>0){
                    result+='(';
                }
                balance++;
            }
            else if(c==')'){
                balance--;
                //phle minus karo to get ki ye outer vla hai ya nhi 
                if(balance>0){
                    result+=')';
                }
            }
        }
        return result;
    }
};