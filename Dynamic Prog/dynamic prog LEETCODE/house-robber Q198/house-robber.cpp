#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
//top down 
    int solve(vector<int>& nums,int n,vector<int>& dp){
        //base case 
        if(n<0){
            return 0;
        }
        if(n==0){
            return nums[n];
        }
        //step 3
        if(dp[n]!=-1){
            return dp[n];
        }
        //step 2
        int incl=solve(nums,n-2,dp)+nums[n];
        int excl=solve(nums,n-1,dp);
    
        dp[n]=max(incl,excl);
        return dp[n];
    }
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        int ans=solve(nums,n-1,dp);
        return ans;
    }
};