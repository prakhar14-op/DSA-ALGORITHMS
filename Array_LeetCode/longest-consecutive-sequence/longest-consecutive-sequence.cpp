#include<iostream>
#include<algorithm>
#include<vector>
#include <climits>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        int last_smallest=INT_MIN;
        int curr_count=0;
        int max_count=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(nums[i]-1==last_smallest){
                curr_count++;
                last_smallest=nums[i];
            }
            else if(nums[i]==last_smallest){
                continue;
            }
            else{
                curr_count=1;
                last_smallest=nums[i];
            }
            max_count=max(max_count,curr_count);
        }
        return max_count;
    }
};