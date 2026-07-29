#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(k+1,0)));
        //why k+1
        //vector<int>(k, 0) creates a size of k (indices 0 to k-1), but your loop uses cap up to k.
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<2;j++){
                for(int cap=1;cap<=k;cap++){
                    if(j){
                        dp[i][j][cap]=max(-prices[i]+dp[i+1][0][cap],dp[i+1][1][cap]);
                    }
                    else{
                        dp[i][j][cap]=max(prices[i]+dp[i+1][1][cap-1],dp[i+1][0][cap]);
                    }
                }
            }
        }
        return dp[0][1][k];
    }
};