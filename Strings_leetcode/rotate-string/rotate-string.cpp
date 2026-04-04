#include<iostream>
using namespace std;
class Solution {
public:
    bool rotateString(string s, string goal) {
        
        int n=s.length();
        for(int j=0;j<n;j++){
            char a=s[0];
            for(int i=0;i<n-1;i++){
                s[i]=s[i+1];
            }
            s[n-1]=a;
            if(s==goal){
                return true;
            }
            
        }
        return false;
        

    }
};