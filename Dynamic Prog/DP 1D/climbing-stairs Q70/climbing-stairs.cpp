#include<bits/stdc++.h>
using namespace std;
class Solution {
//recursion implementation
private:
    // int solve(int n,int i){
    //     if(i==n){
    //         return 1;
    //     }
    //     if(i>n){
    //         return 0;
    //     }
    //     return (solve(n,i+1)+solve(n,i+2));
    // }
    int solve(int n,vector<int>& dp){
        if (n <= 1) return 1;
        if(dp[n]!=-1){
            return dp[n];
        }
        dp[n]=solve(n-1,dp)+solve(n-2,dp);
        return dp[n];
    }
public:
    int climbStairs(int n) {
        //top down lagate hai 
        vector<int> dp(n+1,-1);
        int ans=solve(n,dp);
        return ans;
    }
};