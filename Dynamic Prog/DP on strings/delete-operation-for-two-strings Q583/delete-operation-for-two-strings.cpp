#include<bits/stdc++.h>
using namespace std;
class Solution {
    //step 1 finding the lenght of the common subseq between s1 and s2
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
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        int com_len=f(n-1,m-1,word1,word2,dp);
        int ans=n+m-2*com_len;
        return ans;
    }
};
