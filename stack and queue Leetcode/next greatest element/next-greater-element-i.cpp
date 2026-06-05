#include<bts/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        vector<int> ans(n,-1);
        for(int i=0;i<n;i++){
            int target=nums1[i];
            //finding our target in nums2
            int j=0;
            while(j<m && nums2[j]!=target){
                j++;
            }
            //now our j is at our taget in nums2
            //finding the first next greater element in the right
            for(int k=j+1;k<m;k++){
                if(nums2[k]>target){
                    ans[i]=nums2[k];
                    break;
                }
            }
        }
        return ans;
    }
};