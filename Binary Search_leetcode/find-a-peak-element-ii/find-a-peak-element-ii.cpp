#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
class Solution {
public:
    int find_max(vector<vector<int>>& mat,int m,int n , int ind){
        int max_value=-1;
        int index=-1;
        for(int i=0;i<m;i++){
            if(mat[i][ind]>max_value){
                max_value=mat[i][ind];
                index=i;
            }
        }
        return index;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        int l=0;
        int h=n-1;

        while(l<=h){
            int mid=(l+h)/2;//mid th column 
            int row=find_max(mat,m,n,mid);
            int left=mid-1>=0?mat[row][mid-1]:-1;
            int right=mid+1<n?mat[row][mid+1]:-1;
            if(mat[row][mid]>left && mat[row][mid]>right){
                return {row,mid};
            }
            else if(mat[row][mid]<left){
                h=mid;
            }
            else{
                l=mid+1;
            }
        }
        return {-1,-1};
    }
};


//jab h=mid lo tab while loop l<=h tk 
// jab h=mid-1 lo tab while loop l<h