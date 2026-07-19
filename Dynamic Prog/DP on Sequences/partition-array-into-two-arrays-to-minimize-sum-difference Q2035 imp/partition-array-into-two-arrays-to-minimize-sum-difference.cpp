#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        // int tsize=nums.size();
        // int n=tsize/2;
        // int tsum=0;
        // for(int i=0;i<tsize;i++){
        //     tsum+=nums[i];
        // }
        // vector<vector<bool>> dp(tsize,vector<bool>(tsum+1,0));
        // for(int i=0;i<tsize;i++){
        //     dp[i][0]=true;
        // }
        // if(nums[0]<=tsum){
        //     dp[0][nums[0]]=true;
        // }
        
        // for(int ind=1;ind<tsize;ind++){
        //     for(int target=1;target<=tsum;target++){
        //         bool nottake=dp[ind-1][target];   //doubt
        //         bool take=false;
        //         if(nums[ind]<=target){
        //             take=dp[ind-1][target-nums[ind]];
        //         }
        //         dp[ind][target]=take ||nottake;
        //     }
        // }
        // //dp[n-1][col]
        // int mini=1e9;
        // for(int s1=0;s1<=tsum/2;s1++){
        //     if(dp[n-1][s1]==true){
        //         mini=min(mini,abs((tsum-s1)-s1));
        //     }
        // }
        // return mini;

        int n = nums.size() / 2;
        int total_sum = 0;
        for (int x : nums) total_sum += x;
        
        vector<int> left(nums.begin(), nums.begin() + n);
        vector<int> right(nums.begin() + n, nums.end());

        vector<vector<int>> left_sums(n + 1);
        vector<vector<int>> right_sums(n + 1);
        
        for (int mask = 0; mask < (1 << n); ++mask) {
            int l_sum = 0, l_count = 0;
            int r_sum = 0, r_count = 0;
            for (int i = 0; i < n; ++i) {
                if ((mask >> i) & 1) {
                    l_sum += left[i];
                    l_count++;
                    
                    r_sum += right[i];
                    r_count++;
                }
            }
            left_sums[l_count].push_back(l_sum);
            right_sums[r_count].push_back(r_sum);
        }
        
        for (int k = 0; k <= n; ++k) {
            sort(right_sums[k].begin(), right_sums[k].end());
        }
        
        int min_diff = INT_MAX;
        for (int k = 0; k <= n; ++k) {
            for (int l_sum : left_sums[k]) {

                int target = (total_sum / 2) - l_sum;
                int r_count = n - k;
                
                auto& r_vec = right_sums[r_count];
                auto it = lower_bound(r_vec.begin(), r_vec.end(), target);
                

                if (it != r_vec.end()) {
                    int s1 = l_sum + *it;
                    int s2 = total_sum - s1;
                    min_diff = min(min_diff, abs(s1 - s2));
                }

                if (it != r_vec.begin()) {
                    int s1 = l_sum + *prev(it);
                    int s2 = total_sum - s1;
                    min_diff = min(min_diff, abs(s1 - s2));
                }
            }
        }
        return min_diff;
    }
};
