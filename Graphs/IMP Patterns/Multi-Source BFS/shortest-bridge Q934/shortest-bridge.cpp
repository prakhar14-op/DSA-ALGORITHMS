//step 1 dfs
// step 2bfs level oprder traversal
#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    void dfs(int i,int j,vector<vector<int>>& vis,vector<vector<int>>& grid,int n,queue<pair<int,int>>& q){
        vis[i][j]=1;//marked as visited
        q.push({i, j});
        int drow[]={-1,0,1,0};
        int dcol[]={0,-1,0,1};
        for(int p=0;p<4;p++){
            int newr=i+drow[p];
            int newc=j+dcol[p];
            if(newr>=0 && newr<n && newc>=0 && newc<n){
                if(vis[newr][newc]==-1 && grid[newr][newc] == 1){
                    dfs(newr,newc,vis,grid,n,q);
                }
            }
        }
    }
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int n=grid.size();
        queue<pair<int,int>> q;
        vector<vector<int>> vis(n,vector<int>(n,-1));
        bool found = false;

        // Find first island
        for(int i=0;i<n && !found;i++){
            for(int j=0;j<n && !found;j++){
                if(grid[i][j]==1){
                    
                    dfs(i,j,vis,grid,n,q);
                    found =true;
                    
                }
            }
        }

        //now our step 1 is complete and we have the queue having all the elements of the islands 
        //step 2 :multi source bfs
        //
        int dist=0;
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                auto front=q.front();
                int row=front.first;
                int col=front.second;
                q.pop();
                int drow[]={-1,0,1,0};
                int dcol[]={0,-1,0,1};
                for(int i=0;i<4;i++){
                    int newr=row+drow[i];
                    int newc=col+dcol[i];

                    if(newr<n && newr>=0 && newc<n && newc>=0 && vis[newr][newc]==-1){
                        if(grid[newr][newc]==1){
                            return dist;
                        }
                        vis[newr][newc] = 1;
                        q.push({newr, newc});
                    }
                }
            }
            dist++;
            
        }
        return -1;

    }
};


