#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
        //we will traverse in the grid and mark all the 0 connected to the boundary as true 
        //since those 0 cant be an closed island 
    void dfs(int r,int c,int m,int n,vector<vector<int>>& grid){
        if(r<0 ||c<0 || r>=m || c>=n || grid[r][c] == 1){
            return;
        }
        grid[r][c]=1;
        int drow[]={-1,0,1,0};
        int dcol[]={0,-1,0,1};
        for(int i=0;i<4;i++){
            int newr=r+drow[i];
            int newc=c+dcol[i];
            if(newr<m && newc <n && newr>=0 && newc>=0){
                if(!grid[newr][newc]){
                    dfs(newr,newc,m,n,grid);
                }
            }
        }
    }
public:
    int closedIsland(vector<vector<int>>& grid) {

        int m = grid.size();
        if (m == 0) return 0;
        int n = grid[0].size();

        //right and left travers kar rhe 
        for(int i=0;i<m;i++){
            //left most boundary
            if(grid[i][0]==0){
                dfs(i,0,m,n,grid);
            }
            //right most boundary
            if(grid[i][n-1]==0){
                dfs(i,n-1,m,n,grid);
            }
        }
        //now top and down boundary traversal 
        for(int i=0;i<n;i++){
            //top most boundary traversal
            if(grid[0][i]==0){
                dfs(0,i,m,n,grid);
            }
            //bottom most boundary traversal
            if(grid[m-1][i]==0){
                dfs(m-1,i,m,n,grid);
            }
        }
        //now finding the inner islands since vo closed islands hi honge 
        int closed_islands = 0;
        
        //  We can safely skip the 0th and last rows/cols 
        // because we already processed the perimeter!
        for (int i = 1; i < m - 1; i++) {
            for (int j = 1; j < n - 1; j++) {
                if (grid[i][j] == 0) {
                    closed_islands++;
                    dfs(i, j, m, n,grid); // Sink it to avoid double-counting
                }
            }
        }
        
        return closed_islands;
    }
}; 