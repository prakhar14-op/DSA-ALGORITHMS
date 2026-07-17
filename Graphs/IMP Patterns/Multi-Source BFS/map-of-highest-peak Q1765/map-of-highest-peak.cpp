#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        //if iswater[i][j]==1 then its height =0
        //4 directional movemnt
        //finding all  1  and push in queue and make its dist cell =0
        //then we will do multisource bfs
        int m=isWater.size();
        int n=isWater[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> height(m,vector<int>(n,-1));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(isWater[i][j]==1){
                    q.push({i,j});
                    height[i][j]=0;
                }
            }
        }
        //now queue having all the water cells and height of them is equal to 0
        int drow[]={-1,0,1,0};
        int dcol[]={0,-1,0,1};
        while(!q.empty()){
            auto top=q.front();
            int row=top.first;
            int col=top.second;

            q.pop();

            for(int i=0;i<4;i++){
                int newr=row+drow[i];
                int newc=col+dcol[i];
                if (newr >= 0 && newr < m && newc >= 0 && newc < n){
                    if(height[newr][newc]==-1){
                        height[newr][newc]=height[row][col]+1;
                        q.push({newr, newc});
                    }
                }
            }
        }
        return height;

    }
};