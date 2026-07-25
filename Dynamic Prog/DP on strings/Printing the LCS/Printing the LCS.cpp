#include<bits/stdc++.h>
using namespace std;
class solution{
    //tabulation method
    int lcs(string s,string t){
        int n=s.size();
        int m=t.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
    //printing the lcs 
    string printlcs(string s,string t){
        //step 1 is to find the length of the lcs between s and t
        int n=s.size();
        int m=t.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        //then we will create a string of length equal to the length of the lcs and fill it with '$' and then we will traverse the dp array from the bottom right corner to the top left corner and whenever we find a match we will add that character to the string and move diagonally up left and if there is no match we will move in the direction of the maximum value between the top and left cell.
        int len=dp[n][m];
        string ans="";
        for(int i=0;i<len;i++){
            ans+='$';
        }
        int index=len-1;
        int i=n,j=m;
        while(i>0 && j>0){
            if(s[i-1]==t[j-1]){
                ans[index]=s[i-1];
                index--;
                i--;
                j--;
            }
            else if(dp[i-1][j]>dp[i][j-1]){
                i--;
            }
            else{
                j--;
            }
        }
        return ans;
    }
};