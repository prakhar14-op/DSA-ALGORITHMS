#include<bits/stdc++.h>
using namespace std;
//using the dfs we will traverse the grid and when ever we encounter a 1 and its vis is false we will appply dfs on it and check the number of coinnected 1 and in the main we will sinlutainlys maintain the max area (max number of 1 in an island)
class Solution {
private:
    int dfs(int row,int col,vector<vector<int>>& grid,vector<vector<int>>& vis){
        int m=grid.size();
        int n=grid[0].size();
        int drow[]={-1,-0,1,0};
        int dcol[]={0,-1,0,1};
        if (row < 0 || row >= m || col < 0 || col >= n || vis[row][col] == 1 || grid[row][col] == 0) {
            return 0;
        }
        vis[row][col]=1;
        int numberof_1_count=1;
        for(int i=0;i<4;i++){
            int newr=row+drow[i];
            int newc=col+dcol[i];
            if(newr<m && newr>=0 && newc<n && newc>=0){
                if(!vis[newr][newc]){
                    numberof_1_count+=dfs(newr,newc,grid,vis);
                }
            }
        }
        return numberof_1_count;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        int max_area=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && grid[i][j]==1){
                    int maxi=dfs(i,j,grid,vis);
                    max_area=max(maxi,max_area);
                }
            }
        }
        return max_area;
    }
};