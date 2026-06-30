#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();

        queue<pair<int,int>> q;//{row,col}
        vector<vector<int>> dist(m,vector<int>(n,-1));
        //this -1 os working like our visited matrix vala kam 
        //jha -1 hoga means vha abhi tk koi update nhi huya 
        //and iska mtb not visisted
        //adding all the initial zero
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                    dist[i][j]=0;
                }
            }
        }
        //now doing the bfs
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;

            //for going to neighbour
            int derow[]={-1,0,1,0};
            int decol[]={0,1,0,-1};

            q.pop();
            for(int i=0;i<4;i++){
                int nrow=r+derow[i];
                int ncol=c+decol[i];

                if(nrow>=0 && ncol>=0 && nrow<m && ncol<n && dist[nrow][ncol]==-1){
                    q.push({nrow,ncol});
                    dist[nrow][ncol]=dist[r][c]+1;
                }
            }
        }

        return dist;

    }
};