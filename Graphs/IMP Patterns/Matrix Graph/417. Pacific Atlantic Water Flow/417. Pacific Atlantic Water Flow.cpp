#include<bits/stdc++.h>
using namespace std;
class Solution {
private: 
    void dfs(vector<vector<int>>& heights, int r, int c, int prevHeight, vector<std::vector<bool>>& ocean) {
        int m = heights.size();
        int n = heights[0].size();
        if (r < 0 || r >= m || c < 0 || c >= n || ocean[r][c] || heights[r][c] < prevHeight) {
            return;
        }
        ocean[r][c] = true;
        dfs(heights, r + 1, c, heights[r][c], ocean);
        dfs(heights, r - 1, c, heights[r][c], ocean);
        dfs(heights, r, c + 1, heights[r][c], ocean);
        dfs(heights, r, c - 1, heights[r][c], ocean);
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        // we will find the cells for pacific and atlantic seperatly and then will do the intersection of those cells
        int m=heights.size();
        int n=heights[0].size();
        vector<vector<int>> result;
        if(heights.empty()){
            return result;
        }
        vector<vector<bool>> pacific(m,vector<bool>(n,false));
        vector<vector<bool>> atlantic (m,vector<bool>(n,false));
        for (int r = 0; r < m; ++r) {
            dfs(heights, r, 0, -1, pacific);     // Left column (Pacific)
            dfs(heights, r, n - 1, -1, atlantic); // Right column (Atlantic)
        }
        
        // DFS from the top and bottom border rows
        for (int c = 0; c < n; ++c) {
            dfs(heights, 0, c, -1, pacific);     // Top row (Pacific)
            dfs(heights, m - 1, c, -1, atlantic); // Bottom row (Atlantic)
        }
        
        //intersecting cells where water reaches both oceans
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (pacific[r][c] && atlantic[r][c]) {
                    result.push_back({r, c});
                }
            }
        }
        
        return result;
    }
};