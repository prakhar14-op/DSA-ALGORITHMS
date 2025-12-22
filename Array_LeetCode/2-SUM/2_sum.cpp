//method 1
#include<iostream>
#include<vector>
#include <unordered_map>
using namespace std;
vector<int> twoSum(vector<int>& nums, int target) {
        int length = nums.size();

        int arr[100];
        for(int i=0;i<length;i++){
            for(int j=i + 1;j<length;j++){
                if (nums[i]+nums[j]==target){
                    return {i, j};
                }
               
            }
        }
        return {};
    }

//method 2
vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp; 
        
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            
            if (mp.find(complement) != mp.end()) {
                return {mp[complement], i};
            }
            
            mp[nums[i]] = i;
        }
        
        return {}; 

}
