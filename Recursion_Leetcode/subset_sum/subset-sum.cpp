#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    void generatesubsetsum(int index,int currentsum, vector<int>& nums,vector<int>& result){
        //base case
        if(index==nums.size()){
            result.push_back(currentsum);
            return;
        }
        //dec 1
        generatesubsetsum(index+1,currentsum+nums[index],nums,result);
        //dec 2
        generatesubsetsum(index+1,currentsum,nums,result);
    }
public:
    vector<int> subsetSums(vector<int> nums){
        vector<int> result;
        generatesubsetsum(0,0,nums,result);
        return result;
    }
};