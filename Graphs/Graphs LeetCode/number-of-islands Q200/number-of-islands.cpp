#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    void dfs(int row,int col,vector<vector<int>>& vis,vector<vector<char>>& grid){
        
        int m=grid.size();
        int n=grid[0].size();
        int drow[]={-1,-0,1,0};
        int dcol[]={0,-1,0,1};
        if (row < 0 || row >= m || col < 0 || col >= n || vis[row][col] == 1 || grid[row][col] == '0') {
            return;
        }
        vis[row][col]=1;
        for(int i=0;i<4;i++){
            int newr=row+drow[i];
            int newc=col+dcol[i];
            if(newr<m && newr>=0 && newc<n && newc>=0){
                if(!vis[newr][newc]){
                    dfs(newr,newc,vis,grid);
                }
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        //dfs
        int totalisland=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && grid[i][j] == '1'){
                    totalisland++;
                    dfs(i,j,vis,grid);
                    
                }
            }
        }
        return totalisland;
    }
};