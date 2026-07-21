#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int divide(int dividend, int divisor) {
        //brute force
        // int sum=0;
        // int cnt=0;
        // while(sum+divisor<=dividend){
        //     cnt++;
        //     sum+=divisor;
        // }
        // return cnt;
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        if(dividend==divisor){
            return 1;
        }
        bool sign=true; //+
        if((dividend>=0 && divisor<0) || (dividend<0 && divisor>0)){
            sign=false;//-ve
        }
        int ans=0;
        long long n=abs((long long)dividend);
        long long d=abs((long long)divisor);
        while(n>=d){
            long long cnt=0;
            while(n>=(d<<(cnt+1))){
                cnt++;
            }
            // Use 1LL so the 1 is treated as a 64-bit integer before shifting
            ans=ans+(1LL<<cnt);
            n=n-(d<<cnt);
        }
        if(ans==(1<<31) && sign){
            return INT_MAX;
        }
        if(ans==(1<<31) && !sign){
            return INT_MIN;
        }
        return sign ? ans : -ans;

    }
};