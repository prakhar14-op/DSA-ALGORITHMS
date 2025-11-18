#include<iostream>
using namespace std;

int binary_search(int A[],int l,int h,int key){
    while(l<=h){
        int mid=(l+h)/2;
        if(key==A[mid]){
            return mid;
        }
        else if(key<A[mid]){
            h=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    return -1;
}


int main(){
    int A[]={1,2,4,6,9,22};
    int key;
    cout<<"enter the value you want to search :";
    cin>>key;
    int result_index=binary_search(A,0,5,key);
    cout<<result_index;
}
