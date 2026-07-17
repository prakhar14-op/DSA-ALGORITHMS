#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    bool dfs(int i,int j,vector<vector<int>>& grid1, vector<vector<int>>& grid2){
        //base case ki ham bhar chale jaye grid se 
        int m=grid2.size();
        int n=grid2[0].size();
        if(i<0 || i>=m || j<0 || j>=n ||grid2[i][j]==0){
            return true;
        }
        grid2[i][j] = 0; //marked as visited 
        bool valid =(grid1[i][j]==1);
        bool up=dfs(i-1,j,grid1,grid2);
        bool down=dfs(i+1,j,grid1,grid2);
        bool right=dfs(i,j+1,grid1,grid2);
        bool left=dfs(i,j-1,grid1,grid2);
        return valid && up && down && right && left;
    }
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid1.size();
        int n = grid1[0].size();

        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (grid2[i][j] == 1) {

                    if (dfs(i, j, grid1, grid2))
                        ans++;
                }
            }
        }

        return ans;
    }
};