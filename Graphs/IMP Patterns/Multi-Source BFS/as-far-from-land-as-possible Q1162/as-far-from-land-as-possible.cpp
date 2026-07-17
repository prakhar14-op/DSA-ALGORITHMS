#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        //multi source bfs
        int n=grid.size();
        queue<pair<int,int>> q;
        vector<vector<int>> dist(n,vector<int>(n,-1)); //-1 will rep the unvisited
        //pushing all zero inside the queue
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                    dist[i][j]=0;
                }
            }
        }
        if (q.empty() || q.size() == n * n) return -1;

        //we have make 1 as the source 
        //now doing the multisource bfs
        int drow[]={-1,0,1,0};
        int dcol[]={0,-1,0,1};
        int mx=-1;
        while(!q.empty()){
            auto top=q.front();
            int row=top.first;
            int col=top.second;

            q.pop();
            
            //now going to their neighbour
            for(int i=0;i<4;i++){
                int newr=row+drow[i];
                int newc=col+dcol[i];
                if (newr >= 0 && newr < n && newc >= 0 && newc < n){
                    if(dist[newr][newc]==-1){
                        dist[newr][newc]=dist[row][col]+1;
                        mx = max(mx, dist[newr][newc]);
                        q.push({newr, newc});
                    }
                }
            }
        }
        //now the max value of dist is the ans
        return mx;
        
    }
};