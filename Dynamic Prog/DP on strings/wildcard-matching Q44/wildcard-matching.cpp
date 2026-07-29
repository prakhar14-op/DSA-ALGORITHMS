#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    bool f(int i,int j,string& s,string& p,vector<vector<int>>& dp){
        if(i<0 && j<0){
            return true;
        }
        if(j<0 && i>=0){//patern khtm lakin string bach gyi 
            return false;
        }
        if(i<0 && j>=0){ //string khtm ho gyi lakin pattern bach gya hai abhi
            for(int ii=0;ii<=j;ii++){
                if(p[ii]!='*'){
                    return false;
                }
            }
            return true;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(p[j]==s[i] || p[j] == '?'){
            dp[i][j]=f(i-1,j-1,s,p,dp);
            return f(i-1,j-1,s,p,dp);
        }
        if(p[j]=='*'){
            dp[i][j]=f(i-1,j,s,p,dp) || f(i,j-1,s,p,dp);
            return f(i-1,j,s,p,dp) || f(i,j-1,s,p,dp);
        }
        return dp[i][j]=false;
    }
public:
    bool isMatch(string s, string p) {
        int n=s.length();
        int m=p.length();
        if (n == 0) {
            for (char c : p) {
                if (c != '*') return false;
            }
            return true;
        }
        if (m == 0) return n == 0;

        vector<vector<int>> dp(n,vector<int>(m,-1));
        return f(n-1,m-1,s,p,dp);
    }
};