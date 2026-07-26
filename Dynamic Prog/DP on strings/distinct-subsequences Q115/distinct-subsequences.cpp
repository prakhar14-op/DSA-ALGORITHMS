#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    int f(int i,int j,string& s1,string& s2,vector<vector<int>> &dp){
        //base case 
        if(j<0){
            return 1;
        }
        if(i<0){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        //now exploring all possibilities
        if(s1[i]==s2[j]){
            dp[i][j]=f(i-1,j-1,s1,s2,dp)+f(i-1,j,s1,s2,dp);
            return dp[i][j];
        }
        
        dp[i][j]=f(i-1,j,s1,s2,dp);
        return dp[i][j];
    }
public:
    int numDistinct(string s, string t) {
        int n=s.length();
        int m=t.length();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return f(n-1,m-1,s,t,dp);
    }
};