#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    string convert2binary(int n){
        if (n == 0) return "0";
        string res="";
        while(n>0){
            if(n%2==1){
                res+='1';
            }
            else{
                res+='0';
            }
            n = n / 2;
        }
        
        reverse(res.begin(), res.end()); 
        return res;
    }
    int convert2decimal(string x){
        int len=x.length();
        int num=0;
        long long p2=1;
        for(int i=len-1;i>=0;i--){
            if(x[i]=='1'){
                num=num+p2;
            }
            p2=p2*2;
        }
        return num;
    }
public:
    int reverseBits(int n) {
        // string s=convert2binary(n);
        // //we have to reverse the string 
        // reverse(s.begin(),s.end());
        // int ans=convert2decimal(s);
        // return ans;
        int result=0;
        for(int i=0;i<32;i++){
            result<<=1;
            result|=(n&1);
            n>>=1;
        }
        return result;
    }
};