#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int minprice=prices[0];
        int max_profit=0;

        for(int i=1;i<n;i++){
            minprice=min(minprice,prices[i]);
            max_profit=max(max_profit,prices[i]-minprice);
        }
        return max_profit;
    }
};