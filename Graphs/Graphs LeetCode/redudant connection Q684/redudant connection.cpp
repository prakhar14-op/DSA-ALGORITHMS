#include<bits/stdc++.h>
using namespace std;
class Solution {
 private:
    //DSU
    int find(int node, vector<int>& parent) {
        if (parent[node] == node) {
            return node; 
        }
        return find(parent[node], parent);
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n + 1);
        for(int i = 1; i <= n; i++){
            parent[i] = i; // Initially, every server is its own boss
        }

        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];

            int first=find(u,parent);
            int sec=find(v,parent);

            
            if(first==sec){
                return edge;
            }
            
            else{
                parent[sec]=first;
            }
            
        }

        return {}; 
    }
};