#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low=0;
        int high=nums.size()-1;

        while(low<=high){
            int mid=(low+high)/2;

            if(nums[mid]==target){
                return mid;
            }
            //checking that the left array is sorted ?
            if(nums[low]<=nums[mid]){
                //checking target is lying in the left sorted array 
                if(nums[low]<=target && target<=nums[mid]){
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            }
            //otherwise right array is sorted 
            else{
                //checking that target lies in right array 
                if(nums[mid]<=target && target<=nums[high]){
                    low=mid+1;
                }
                //means it lies in the left 
                else{
                    high=mid-1;
                }
            }
        }
        return -1;
    }
};