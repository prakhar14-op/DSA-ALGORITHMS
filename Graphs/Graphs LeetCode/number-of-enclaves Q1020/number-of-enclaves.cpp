#include<bits/std.c++.h>
using namespace std;
class Solution {
private: 
    void dfs(vector<vector<int>>& board, int r, int c) {
        int m = board.size();
        int n = board[0].size();
        if (r < 0 || c < 0 || r >= m || c >= n || board[r][c] != 1) {
            return;
        }
        board[r][c] = -1; 

        dfs(board, r + 1, c); // Down
        dfs(board, r - 1, c); // Up
        dfs(board, r, c + 1); // Right
        dfs(board, r, c - 1); // Left
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        //step1
        // Sweep Top and Bottom rows
        for (int j = 0; j < n; j++) {
            if (grid[0][j] == 1){
                dfs(grid, 0, j);
            } 
            if (grid[m - 1][j] == 1) {
                dfs(grid, m - 1, j);
            }
        }
        
        // Sweep Left and Right columns
        for (int i = 0; i < m; i++) {
            if (grid[i][0] == 1) {
                dfs(grid, i, 0);
            }
            if (grid[i][n - 1] == 1) {
                dfs(grid, i, n - 1);
            }
        }
        //last step to just converting '0'->'x'  and 't'->'0'
        int ans=0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    ans+=1;
                }
            }
        }
        return ans;
    }
};