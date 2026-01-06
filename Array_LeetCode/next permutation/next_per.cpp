#include<iostream>
using namespace std;
#include<vector>
#include <algorithm>
#include <numeric>
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        next_permutation(nums.begin(),nums.end());
    }
};
    //     int ind=-1;
    //     int n=nums.size();
    //     for(int i=n-2;i>=0;i--){
    //         if(nums[i]<nums[i+1]){
    //             ind=i;
    //             break;
    //         }
    //     }

    //     if(ind==-1){
    //         reverse(nums.begin(),nums.end());
    //     }

    //     for(int i=n-1;i>=0;i--){
    //         if(nums[i]>nums[ind]){
    //             swap(nums[i],nums[ind]);
    //         }
    //     }

    //     reverse(nums.begin()+ind+1,nums.end());
        

