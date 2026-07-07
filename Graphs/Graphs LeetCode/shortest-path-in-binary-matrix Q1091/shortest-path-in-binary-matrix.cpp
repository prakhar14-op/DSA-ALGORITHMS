#include<bits/std.c++.h>
using namespace std;
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        //this is undirected graopgh so using the bfs algo in this 
        //source is (0,0)
        //target is (n-1,n-1)
        //not weighted so taking unit weights 
        // we can go only on those blocks having 0 
        int n=grid.size();
        if(grid[0][0]==1 || grid[n-1][n-1]){
            return -1;
        }
        //making the queue
        queue<pair<int, pair<int, int>>> q; //{distance, {row, col}}
        q.push({1,{0,0}});
        grid[0][0]=1;// visited mark kar diya 

        //we can move in 8 direction 
        int dRow[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dCol[] = {-1, 0, 1, -1, 1, -1, 0, 1};
        //lets do bfs
        while(!q.empty()){
            auto curr = q.front();
            q.pop();

            int dist = curr.first;
            int row = curr.second.first;
            int col = curr.second.second;

            // Base Case
            if (row == n - 1 && col == n - 1) {
                return dist;
            }
            for(int i = 0; i < 8; i++) {
                int nrow = row + dRow[i];
                int ncol = col + dCol[i];
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < n && grid[nrow][ncol] == 0) {
                    q.push({dist + 1, {nrow, ncol}});
                    grid[nrow][ncol] = 1;
                
                }
            }   
        }
        return -1;
    }
};