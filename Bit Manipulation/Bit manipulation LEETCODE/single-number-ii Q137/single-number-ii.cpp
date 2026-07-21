#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result=0;
        for(int i=0;i<32;i++){
            int sum=0;
            //going to each element of nums and checking the ith index of their bit rep 
            for(auto num:nums){
                if(num&(1<<i)){
                    sum++;
                }
            }
            if(sum%3!=0){
                result=result | (1<<i);
            }
        }
        return result;
    }
};