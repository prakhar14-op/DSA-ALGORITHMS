#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n=arr.size();
        int l=0;
        int h=n-1; //postion nikal rhe hai, Because you are doing arr[mid] inside the loop, mid must be a valid array index.

        while(l<=h){
            int mid=(l+h)/2;
            if((arr[mid]-(mid+1))<k){
                l=mid+1;
            }
            else{
                h=mid-1;
            }
        }
        return l+k;
    }
};