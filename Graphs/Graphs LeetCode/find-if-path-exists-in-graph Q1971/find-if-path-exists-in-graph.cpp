#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    bool dfs(int source,int destination,vector<int>& vis, unordered_map<int, vector<int>>& adj){
        bool ans=true;
        vis[source]=1;
        if(source==destination){
            return true;
        }
        for(auto neig:adj[source]){
            if(!vis[neig]){
                if(dfs(neig,destination,vis,adj)){
                    return true;
                }
            }
        }
        return false;
    }
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        //creating the adj list 
        unordered_map<int, vector<int>> adj;
        // int n=edges.size();
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> vis(n,0);
        //not looping on all the nodes since thewy can be in diff components 
        bool ans=dfs(source,destination,vis,adj);
        return ans;
    }
};