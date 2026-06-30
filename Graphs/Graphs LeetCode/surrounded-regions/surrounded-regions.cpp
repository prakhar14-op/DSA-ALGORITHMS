#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    void dfs(vector<vector<char>>& board, int r, int c) {
        int m = board.size();
        int n = board[0].size();
        if (r < 0 || c < 0 || r >= m || c >= n || board[r][c] != 'O') {
            return;
        }
        board[r][c] = 'T'; 

        dfs(board, r + 1, c); // Down
        dfs(board, r - 1, c); // Up
        dfs(board, r, c + 1); // Right
        dfs(board, r, c - 1); // Left
    }
public:
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        //step1
        // Sweep Top and Bottom rows
        for (int j = 0; j < n; j++) {
            if (board[0][j] == 'O'){
                dfs(board, 0, j);
            } 
            if (board[m - 1][j] == 'O') {
                dfs(board, m - 1, j);
            }
        }
        
        // Sweep Left and Right columns
        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O') {
                dfs(board, i, 0);
            }
            if (board[i][n - 1] == 'O') {
                dfs(board, i, n - 1);
            }
        }
        //last step to just converting '0'->'x'  and 't'->'0'
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O') {

                    board[i][j] = 'X';
                } else if (board[i][j] == 'T') {

                    board[i][j] = 'O';
                }
            }
        }

        
    }
};