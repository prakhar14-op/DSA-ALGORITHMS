#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> positive;
        vector<int> negative;
        vector<int> final_ans;
        int size=nums.size();
        for(int i=0;i<size;i++){
            if(nums[i]>0){
                positive.push_back(nums[i]);
            }
            else{
                negative.push_back(nums[i]);
            }
        }
        //merging
        int p=0;
        int n=0;// seperate indices
        for(int i=0;i<size;i++){
            if(i%2==0){
                final_ans.push_back(positive[p++]);
            }
            else{
                final_ans.push_back(negative[n++]);
            }
        }
        return final_ans;

    }
};