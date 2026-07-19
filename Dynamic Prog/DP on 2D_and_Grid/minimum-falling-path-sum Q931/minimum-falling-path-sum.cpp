#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
//memoization
    int solve(int i,int j,vector<vector<int>>& dp,vector<vector<int>>& matrix){
        int n=matrix.size();
        if(j<0 || j>=n){
            return 1e9;
        }
        if(i==0){
            return matrix[0][j];
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int s=matrix[i][j]+solve(i-1,j,dp,matrix);
        int ld=matrix[i][j]+solve(i-1,j-1,dp,matrix);
        int rd=matrix[i][j]+solve(i-1,j+1,dp,matrix);
        dp[i][j]=min(s,min(ld,rd));
        return dp[i][j];
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        // int ans=1e9;
        // for(int i=0;i<n;i++){
        //     int comp=solve(n-1,i,dp,matrix);
        //     if(comp<ans){
        //         ans=comp;
        //     }
        // }
        // return ans;

        //method 2: tabulation
        //tabulation
        // for(int i=0;i<n;i++){
        //     dp[0][i]=matrix[0][i];
        // }
        // for(int i=1;i<n;i++){
        //     for(int j=0;j<n;j++){
                
        //         if(j>=0 && j<n){
        //             int s=matrix[i][j]+solve(i-1,j,dp,matrix);
        //             int ld=matrix[i][j]+solve(i-1,j-1,dp,matrix);
        //             int rd=matrix[i][j]+solve(i-1,j+1,dp,matrix);
        //             dp[i][j]=min(s,min(ld,rd));
        //         }
                
        //     }
        // }
        // int mini=dp[n-1][0];
        // for(int i=1;i<n ;i++){
        //     mini=min(mini,dp[n-1][i]);
        // }
        // return mini;
        
    
        //method 3 
        if (n == 0) return 0;
        
        vector<int> prev(n);
        for(int j = 0; j < n; ++j) {
            prev[j] = matrix[0][j];
        }
        
        for (int i = 1; i < n; ++i) {
            vector<int> curr(n);
            for (int j = 0; j < n; ++j) {
                int up = prev[j];
                int leftDiagonal = (j > 0) ? prev[j - 1] : 1e9;
                int rightDiagonal = (j < n - 1) ? prev[j + 1] : 1e9;
                
                curr[j] = matrix[i][j] + min(up, min(leftDiagonal, rightDiagonal));
            }
            prev = curr;
        }
        
        return *min_element(prev.begin(), prev.end());
    }
};