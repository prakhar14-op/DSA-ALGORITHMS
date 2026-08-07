#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    bool dfs(int current,vector<int>& arr,vector<bool>& vis){
        //base case
        if(current<0 ||current>=arr.size()){
            return false;
        }
        //Already visited (caught in a cycle)
        if(vis[current]){
            return false;
        }
        if(arr[current]==0){
            return true;
        }
        vis[current]=true;
        return dfs(current+arr[current],arr,vis) || dfs(current-arr[current],arr,vis);
    }
public:
    bool canReach(vector<int>& arr, int start) {
        int n=arr.size();
        vector<bool> vis(n,false);
        return dfs(start,arr,vis);
    }
};