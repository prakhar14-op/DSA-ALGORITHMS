#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
class Solution {
public:
    int minDays(vector<int>& bloomday, int m, int k) {
        int n=bloomday.size();
        
        int l=*min_element(bloomday.begin(),bloomday.end());
        int hi=*max_element(bloomday.begin(),bloomday.end());

        long long c=(long long)m*k;
        if(c>n){
            return -1;
        }

        while(l<hi){
            int mid=(l+hi)/2;

            int adj_flowers=0;
            int bouquets_count=0;

            for(int i=0;i<n;i++){
                if(bloomday[i]<=mid){
                    adj_flowers++;

                    if(adj_flowers==k){
                        bouquets_count++;
                        adj_flowers=0;
                    }
                    
                }
                else{
                    adj_flowers=0;
                }
                
            }

            if(bouquets_count<m){
                l=mid+1;
            }
            else{
                hi=mid;
            }
        }
        return l;
    }
};