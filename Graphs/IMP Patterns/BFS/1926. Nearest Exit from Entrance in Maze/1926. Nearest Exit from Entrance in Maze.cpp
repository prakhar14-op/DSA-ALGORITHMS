#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m=maze.size();
        int n=maze[0].size();
        
        queue<pair<int,pair<int,int>>> q; //{steps to reach,{row,col}}
        //marking inplace since if we use the general visited array we will not be able to not go to the cells having walls
        //if want to use vis
        //loop over the maze and when you find a wall mark that cell visited 
        //now you can use this vis array but the t.c will become O(N^2)
        maze[entrance[0]][entrance[1]]='+';

        q.push({0,{entrance[0],entrance[1]}});

        int dr[]={-1,0,1,0};
        int dc[]={0,-1,0,1};
        while(!q.empty()){
            auto f=q.front();
            int steps=f.first;
            int row=f.second.first;
            int col=f.second.second;
            
            //since the entrance is not be consider as the exit s
            if( (row!=entrance[0] || col!=entrance[1]) &&(row==0 || col==0 || row==m-1 ||col==n-1)){
                return steps;//bfs will give us the min automatically since it is a prop of bfs
            }
            q.pop();
            
            //now traversong to its neighbours 
            for(int i=0;i<4;i++){
                int nrow=row+dr[i];
                int ncol=col+dc[i];
                if(nrow<m && nrow>=0 && ncol<n && ncol>=0 ){
                    if(maze[nrow][ncol]=='.'){
                        q.push({steps+1,{nrow,ncol}});
                        maze[nrow][ncol]='+';
                    }
                }
            }
        }
        return -1;

    }
};