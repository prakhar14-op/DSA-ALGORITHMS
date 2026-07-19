#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    int solve(int i,int j,vector<vector<int>>& dp,vector<vector<int>>& grid){
        //base case 
        if(i==0 && j==0){
            return grid[0][0];
        }
        if(i<0 || j<0){
            return 1e9+7;
        }
        //step 3 of dp
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int up=solve(i-1,j,dp,grid)+grid[i][j];
        int left=solve(i,j-1,dp,grid)+grid[i][j];
        dp[i][j]=min(up,left);
        return dp[i][j];

    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        int ans=solve(m-1,n-1,dp,grid);
        return ans;
    }
};