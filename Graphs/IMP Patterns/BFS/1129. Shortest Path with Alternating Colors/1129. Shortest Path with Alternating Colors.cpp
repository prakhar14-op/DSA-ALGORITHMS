#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        //in short we are given two graphs 
        //they can intersect or cant
        //creating the adj list

        vector<vector<int>> adj_red(n);
        for(auto it:redEdges){
            int a=it[0];
            int b=it[1];
            adj_red[a].push_back(b);
        }

        vector<vector<int>> adj_blue(n);
        for(auto it:blueEdges){
            int u=it[0];
            int v=it[1];
            adj_blue[u].push_back(v);
        }
        vector<int> result(n,-1);
        result[0]=0;
        //in this we can come to a node again so not using the normal visited array instead we will make a track of the incoming color as well
        vector<vector<bool>> vis(n,vector<bool>(2,false));
        queue<pair<int,pair<int,int>>> q;//{node{steps,color}}
        q.push({0,{0,0}}); //color=0:red , color =1:blue
        q.push({0,{0,1}});

        vis[0][0]=true;
        vis[0][1]=true;
        while(!q.empty()){
            auto f=q.front();
            q.pop();
            int node=f.first;
            int step=f.second.first;
            int color=f.second.second;

            //since we are doing the bfs we will automaticaly have the smallest dist to each node so if for a given node there is already an entry in the result we will not update that 
            if(result[node]==-1){
                result[node]=step;
            }
            //doing normal bfs traversal but we will travers to the diff color as we have right now 
            if(color==0){
                //means now we have to go to the blue edge 
                for(int it:adj_blue[node]){
                    if(!vis[it][1]){
                        vis[it][1]=true;
                        q.push({it,{step+1,1}});
                    }
                }
            }
            else{
                //means the incoming color was blue now we want the red color 
                for(int it:adj_red[node]){
                    if(!vis[it][0]){
                        vis[it][0]=true;
                        q.push({it,{step+1,0}});
                    }
                }
            }
        }
        return result;
    }
};