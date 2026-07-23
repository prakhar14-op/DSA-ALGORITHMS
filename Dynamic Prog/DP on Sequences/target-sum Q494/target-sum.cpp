#include<bits/srdc++.h>
using namespace std;
class Solution {
int MOD=(int)(1e9+7);
private:
    int f(int ind,int target,vector<int>& nums,vector<vector<int>>& dp){
        if(ind==0){
            //We can pick it (+0) or not pick it (-0), both give target 0.
            if(target==0 && nums[0]==0) return 2;
            //Otherwise, we return 1 if we found the exact target, else 0
            if(target==0 || nums[0]==target) return 1;
            return 0;
        }
        if(dp[ind][target]!=-1){
            return dp[ind][target];
        }

        //// Pick / Don't Pick Logic
        int not_take=f(ind-1,target,nums,dp);
        int take=0;
        if(nums[ind]<=target){
            take=f(ind-1,target-nums[ind],nums,dp);
        }
        return dp[ind][target]=not_take+take;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum = 0;
        for (int num : nums) {
            totalSum += num;
        }
        
        // Edge Cases:
        // If totalSum + target is odd, it's mathematically impossible to divide by 2 evenly.
        // If the absolute target is greater than totalSum, it's impossible to reach.
        if ((totalSum + target) % 2 != 0 || abs(target) > totalSum) {
            return 0;
        }
        
        int s1 = (totalSum + target) / 2;
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(s1 + 1, -1));
        
        return f(n - 1, s1, nums, dp);
    }
};