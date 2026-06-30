#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));//imp
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
                else{
                    vis[i][j]=0;
                }
            }
        }

        int tm=0;
        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int t=q.front().second;

            tm=max(tm,t); ///doubt
            //for going to neighbour
            int derow[]={-1,0,1,0};
            int decol[]={0,1,0,-1};

            q.pop();
            for(int i=0;i<4;i++){
                int nrow=r+derow[i];
                int ncol=c+decol[i];

                if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && vis[nrow][ncol]!=1 && grid[nrow][ncol]==1){
                    q.push({{nrow,ncol},t+1});
                    vis[nrow][ncol]=1;
                }
            }
        }

        //checking koi frwsh to nhi rhe gya
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]!=1 && grid[i][j]==1){
                    return -1;
                }
            }
        }
        return tm;
    }
};