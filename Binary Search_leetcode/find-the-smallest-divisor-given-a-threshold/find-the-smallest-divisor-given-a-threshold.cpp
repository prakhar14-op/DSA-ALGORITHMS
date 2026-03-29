#include<vector>
#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();
        int l=1;// so division by zero ka dar khtm ho jaye
        int h = *max_element(nums.begin(), nums.end());

        while(l<h){
            int mid=(l+h)/2;
            int sum=0;
            for(int i=0;i<n;i++){
                sum+=ceil((double)nums[i]/mid);// int divide by int will be int so yha type change lagna pada 
            }
            if(sum<= threshold){
                h=mid;
            }
            else{
                l=mid+1;
            }
        }
        return l;
    }
};



//Use h = n - 1 when your binary search is trying to find a position inside an array (like "find the target number in this sorted array").

//Use h = *max_element when your binary search is trying to find a hypothetical number that might not even exist inside the array (like "find a speed" or "find a divisor").