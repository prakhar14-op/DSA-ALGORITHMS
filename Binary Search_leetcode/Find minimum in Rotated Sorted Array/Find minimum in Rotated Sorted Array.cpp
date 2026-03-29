#include<vector>
#include<iostream>
using namespace std;
class Solution {

public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int l=0;
        int h=n-1;
        // If the array isn't rotated at all
        if (nums[l] <= nums[h]){
            return nums[l];
        } 
        
        
        while(l<h){
            int mid=(l+h)/2;
            int minn=nums[mid];
            if (nums[mid] > nums[h]) {
                l = mid + 1;
            } 
            // Otherwise, the min is to the left (including mid)
            else {
                h = mid;
            }
        }
        return nums[l];
    
    }
};