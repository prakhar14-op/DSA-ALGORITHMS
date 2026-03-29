#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n=nums.size();
        int l=0;
        int h=n-1;
        
        while(l<=h){
            int mid=(l+h)/2;
            if(nums[mid]==target){
                return true;
            }
            //when duplicates aa jaye 
            if (nums[l] == nums[mid] && nums[mid] == nums[h]) {
                l++;
                h--;
                continue;
            }
            else{
                if(nums[l]<=nums[mid]){
                    if(target>=nums[l] && target<nums[mid]){
                        h=mid-1;
                    }
                    else{
                        l=mid+1;
                    }
                }
                else{
                    if(target<=nums[h] && target>nums[mid]){
                        l=mid+1;
                    }
                    else{
                        h=mid-1;
                    }
                }
            }
        }
        return false;
    }
};