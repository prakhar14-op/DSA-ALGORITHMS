#include<bits/stdc++.h>
using namespace std;
class Solution {
// private:
//     int solve(int row,int col,vector<vector<int>>& dp,vector<vector<int>>& triangle){
//         int n=triangle.size();
//         if(row==n-1){
//             return triangle[row][col];
//         }
//         if(dp[row][col]!=-1){
//             return dp[row][col];
//         }
//         int down=triangle[row][col]+solve(row+1,col,dp,triangle);
//         int diag=triangle[row][col]+solve(row+1,col+1,dp,triangle);
//         dp[row][col]=min(down,diag);
//         return dp[row][col];

        
//     }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        // int ans=solve(0,0,dp,triangle);
        // return ans;

        //tabulation
        for(int i=0;i<n;i++){
            dp[n-1][i]=triangle[n-1][i];
        }
        for(int i=n-2;i>=0;i--){
            for(int j=i;j>=0;j--){
                int down=triangle[i][j]+dp[i+1][j];
                int diag=triangle[i][j]+dp[i+1][j+1];
                dp[i][j]=min(down,diag);
            }
        }
        return dp[0][0];
;    }
};