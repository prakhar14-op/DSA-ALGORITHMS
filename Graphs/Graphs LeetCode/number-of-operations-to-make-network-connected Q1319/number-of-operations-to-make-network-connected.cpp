#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    void dfs(int node,vector<bool> &visited,vector<vector<int>> &adjlist,vector<int>& component){
        component.push_back(node);
        visited[node]=true;
        for(auto i:adjlist[node]){
            if(!visited[i]){
                dfs(i,visited,adjlist,component);
                
            }
        }
    }
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int v=connections.size();
        if (connections.size() < n - 1) return -1;
        //creating the adj list 
        vector<vector<int>> adjlist(n);
        for(auto it:connections){
            int u=it[0];
            int v=it[1];
            adjlist[u].push_back(v);
            adjlist[v].push_back(u);
        }
        int totalProvinces=0;
        vector<bool> visited(n,false);
        vector<int> components;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                totalProvinces++;
                dfs(i, visited, adjlist, components);
            }
        }
        return  totalProvinces-1;
    }
};
