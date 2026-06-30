#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    bool dfs(int node,int col,vector<int>& color,vector<vector<int>>& adj){
        color[node]=col;
        for(auto it:adj[node]){
            if(color[it]==-1){
                if(dfs(it,!col,color,adj)==false){
                    return false;
                }
            }
            else if(color[it]==col){
                return false;
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();// row of adj matrix is no of nodes 
        vector<int> color(n, -1);
        for(int i=0;i<n;i++){
            color[i]=-1;
        }
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(dfs(i,0,color,graph)==false){
                    return false;
                }
            }
        }
        return true;
    }
};

//Imagine your DFS call stack is a chain of command:

// The Manager (your main loop) sends a Worker to Node 0.

// Node 0 sends a sub-worker to Node 1.

// Node 1 sends a sub-worker to Node 2.

// Node 2 spots a massive system failure (an odd-length cycle!) and returns false.

// If Node 1 just called dfs(2) without checking the result, the sub-worker returns false, but Node 1 simply shrugs, finishes its loop, and tells Node 0: "Everything looks good here! Returning true!" The error is completely swallowed and lost in memory.