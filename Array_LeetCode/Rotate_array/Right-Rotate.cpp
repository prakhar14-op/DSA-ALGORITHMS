#include<iostream>
using namespace std;
void right_rotate(int arr[], int n , int d){
    d=d%n;
    int temp[d];
    for(int i=0;i<d;i++){
        temp[i]=arr[n-d+i];
    }

    //step 1 of right rotation
    for(int i=n-d-1;i>=0;i--){
        arr[i+d]=arr[i];
    }

    //re adding the temp into the array at the end 
    for(int i=0;i<d;i++){
        arr[i]=temp[i];
    }
}

int main(){
    int n;
    cout<<"enter the size of array ";
    cin>>n;
    int nums[n];
    cout<<"enter the values";
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    int d;
    cout<<"enter the value by which you have to rotate the array to right ";
    cin>>d;
    right_rotate(nums,n,d);
    cout<<"the rotated array is :";
    for(int i=0;i<n;i++){
        cout<<nums[i]<<" ";
    }
}