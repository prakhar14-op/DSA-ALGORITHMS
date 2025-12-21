#include<iostream>
#include <vector>

using namespace std;
void moving_zero(vector<int>& nums){
    int n=nums.size();
    int j=-1;
    for(int i=0;i<n;i++){
        if(nums[i]==0){
            j=i;
            break;
        }
    }

    if(j==-1) return;

    for(int i=j+1;i<n;i++){
        if(nums[i]!=0){
            swap(nums[i],nums[j]);
            j++;
        }
    }
}

int main(){
    vector<int> nums ={1,0,2,0,3,4,0,0,5,0,6,0,7};
    int n=nums.size();
    moving_zero(nums);
    cout<<"after moving all zeroes to the end :"<<"\n";
    for(int i =0;i<n;i++){
        cout<<nums[i]<<" ";
    }
}