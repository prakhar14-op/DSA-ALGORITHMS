#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    int solve(int i,int j,vector<vector<int>>& dp,vector<vector<int>>& obstacleGrid){
        //base case 
        if(i==0 && j==0){
            return 1;
        }
        if(i>=0 && j>=0 && obstacleGrid[i][j]==1){
            return 0;
        }
        if(i<0 || j<0){
            return 0;
        }
        //step 3 of dp
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int up=solve(i-1,j,dp,obstacleGrid);
        int left=solve(i,j-1,dp,obstacleGrid);
        dp[i][j]=up+left;
        return dp[i][j];

    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        //boundary cases l
        if (obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1) {
            return 0;
        }
        int ans=solve(m-1,n-1,dp,obstacleGrid);
        return ans;
    }
}; 