#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    int f(int ind1,int ind2,string& s1,string& s2,vector<vector<int>>& dp){
        if(ind1<0 ||ind2<0){
            return 0;
        }
        if(dp[ind1][ind2]!=-1){
            return dp[ind1][ind2];
        }
        //match
        if(s1[ind1]==s2[ind2]){
            dp[ind1][ind2]=1+f(ind1-1,ind2-1,s1,s2,dp);
            return 1+f(ind1-1,ind2-1,s1,s2,dp);
        }
        //not match
        dp[ind1][ind2]=max(f(ind1-1,ind2,s1,s2,dp),f(ind1,ind2-1,s1,s2,dp));
        return max(f(ind1-1,ind2,s1,s2,dp),f(ind1,ind2-1,s1,s2,dp));
    }
public:
    int longestPalindromeSubseq(string s) {
        int n=s.length();
        string r = s;
        reverse(r.begin(), r.end());
        vector<vector<int>> dp(n,vector<int>(n,-1));
        int ans=f(n-1,n-1,s,r,dp);
        return ans;
    }
};