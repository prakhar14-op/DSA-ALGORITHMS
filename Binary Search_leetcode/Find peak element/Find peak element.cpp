
#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l=0;
        int n= nums.size();
        int h=n-1;
        
        while(l<h){
            int mid=(l+h)/2;
            if(nums[mid]<nums[mid+1]){
                l=mid+1;
            }
            else{
                h=mid;
            }
        }
        return l;
    }
};