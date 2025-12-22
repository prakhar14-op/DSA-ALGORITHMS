#include<iostream>
#include<vector>
using namespace std;
//method1:counting method
void sortColors(vector<int>& nums) {
    int n=nums.size();
    int count_0=0;
    int count_1=0;
    int count_2=0;
    for(int i=0;i<n;i++){
        if(nums[i]==0){
            count_0++;
        }
        else if(nums[i]==1){
            count_1++;
        }
        else if(nums[i]==2){
            count_2++;
        }
    }

    //adding 0's 1's 2's in an array
    for(int i=0;i<count_0;i++){
        nums[i]=0;
    }

    for(int i=0;i<count_1;i++){
        nums[i+count_0]=1;
    }
    for(int i=0;i<count_2;i++){
        nums[i+count_0+count_1]=2;

    }
}

//method2:Dutch National Flag Algorithm
void sortColors_2(vector<int>& nums) {
    int low = 0;
    int mid = 0;
    int high = nums.size() - 1;

    while(mid <= high){
        if(nums[mid] == 0){
            swap(nums[low], nums[mid]);
            low++;
            mid++;
        }
        else if(nums[mid] == 1){
            mid++;
        }
        else{ // nums[mid] == 2
            swap(nums[mid], nums[high]);
            high--;
        }
    }
}

int main(){
    vector<int> nums;
    nums={1,0,0,2,1,0,2};

    int n=nums.size();
    sortColors(nums);
    for(int i=0;i<n;i++){
        cout<<nums[i]<<" ";
    }
}

