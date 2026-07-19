#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    bool subsetsumtok(int n,int k,vector<int>& arr){
        vector<bool> prev(k+1,0),curr(k+1,0);
        prev[0]=curr[0]=true;
        if(arr[0]<k){
            prev[arr[0]]=true;
        }
        
        for(int ind =1;ind<n;ind++){
            for(int target=1;target<=k;target++){
                bool not_take=prev[target];
                bool take=false;
                if(arr[ind]<=target) take=prev[target-arr[ind]];
                curr[target]=take || not_take;
            }
            prev=curr;
        }
        return prev[k];
    }
public:
    bool canPartition(vector<int>& nums) {
        int total_sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            total_sum+=nums[i];
        }
        if(total_sum%2!=0){
            return false;
        }
        int target=total_sum/2;
      
        return subsetsumtok(n,target,nums);
    }
};