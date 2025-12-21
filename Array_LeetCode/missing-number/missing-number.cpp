//method 1
#include<iostream>
#include<vector>
using namespace std ;
// class Solution {
// public:
//     int missingNumber(vector<int>& nums) {
//         //sorting the nums then we will find 
//         int n=nums.size();
//         sort(nums.begin(),nums.end());
//         if (nums[0] != 0) return 0;


//         //now searching for the misiing value 
//         for(int i=0;i<n-1;i++){
//             if(nums[i+1]!=nums[i]+1){
//                 return nums[i]+1;
//             }
//         }
//         return nums.size();

//     }
// };


//method 2
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int total = n * (n + 1) / 2;
        int sum = 0;

        for (int x : nums) {
            sum += x;
        }

        return total - sum;
    }
};
