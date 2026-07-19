#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    int fibo(int n,vector<int>& dp){
        if(n<=1){
            return n;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        dp[n]= fibo(n-1,dp)+fibo(n-2,dp);
        return dp[n];
    }
public:
    int fib(int n) {
        vector<int> dp(n+1,-1);
        return fibo(n,dp);
    }
};