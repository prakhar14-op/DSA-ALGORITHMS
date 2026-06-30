#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    vector<vector<int>> convertMatrixToList(vector<vector<int>>& matrix) {
    int V = matrix.size();
    vector<vector<int>> adjList(V);

    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; j++) {
            if (matrix[i][j] != 0) { 
                adjList[i].push_back(j);
            }
        }
    }
    return adjList;
    }
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
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<vector<int>> adjlist=convertMatrixToList(isConnected);
        int v=isConnected.size();
        int totalProvinces=0;
        vector<bool> visited(v,false);
        vector<int> components;
        for (int i = 0; i < v; i++) {
            if (!visited[i]) {
                totalProvinces++;
                dfs(i, visited, adjlist, components);
            }
        }
        
        return totalProvinces;
        
    }
};