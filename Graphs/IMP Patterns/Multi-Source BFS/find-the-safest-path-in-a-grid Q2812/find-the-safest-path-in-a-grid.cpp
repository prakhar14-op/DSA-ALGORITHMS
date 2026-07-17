#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        //calulating the manthan distance of evry cel; before finding the path 
        int n=grid.size();
        //using queue for multi source bfs
        queue<pair<int,int>> q;

        vector<vector<int>> dist(n,vector<int>(n,1e9));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                //intitializing queue with all the source (all theif)
                if(grid[i][j]==1){
                    q.push({i,j});
                    //making their distmace =0
                    dist[i][j]=0;
                }
            }
        }
        //now we have to do bfs
        //this will give us the final distance matrix having safety factor as weight of each cell
        int drow[]={-1,0,1,0};
        int dcol[]={0,-1,0,1};
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
                    if(dist[newr][newc]==1e9){
                        dist[newr][newc]=dist[row][col]+1;
                        q.push({newr, newc});
                    }
                }
                //and if not infinty means phle se koi theif aa gya and uska distance kam 
            }
        }
        //now we have the distance matrix ready Every cell (r, c) contains its shortest Manhattan distance to the nearest thief
        //we will use this as our weights 
        //ham us raste jayenge jaha max weight 
        //so we have to modify the dijkstra


        //using the normal priorty queu sine it is max heap by default
        priority_queue<pair<int,pair<int,int>>> qu;// {saftest factor{row,col}}
        vector<vector<int>> max_safeness(n, vector<int>(n, -1));
        max_safeness[0][0] = dist[0][0];
        if(dist[0][0]==0){
            return 0;
        }
        qu.push({dist[0][0],{0,0}});
        while(!qu.empty()){
            auto front=qu.top();
            int currdist=front.first;
            int row=front.second.first;
            int col=front.second.second;
            qu.pop();
            if(row==n-1 && col==n-1){
                return currdist;
            }

            //going to neighbour
            for(int i=0;i<4;i++){
                int nr=row+drow[i];
                int nc=col+dcol[i];
                
                if (nr >= 0 && nr < n && nc >= 0 && nc < n){
                    
                    //The safeness factor of a path on the grid is defined as the minimum manhattan distance from any cell in the path to any thief in the grid.

                    int new_path_safeness = min(currdist, dist[nr][nc]);
                    if (new_path_safeness > max_safeness[nr][nc]) {
                        max_safeness[nr][nc] = new_path_safeness;
                        qu.push({new_path_safeness, {nr, nc}});
                    }
                }

            }
        }
        return 0;


    }
};