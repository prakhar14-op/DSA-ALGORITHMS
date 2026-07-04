#include<bits/stdc++.h>
using namespace std;
class solution{
private:
    void dfs(int node, unordered_map<int,vector<int>>& adj, vector<bool>& visited, stack<int>& st){
        visited[node]=true;
        for(auto it:adj[node]){
            if(!visited[it]){
                dfs(it,adj,visited,st);
            }
        }
        st.push(node);
    }
public:
    vector<int> toposort(vector<vector<int>>& edges, int v, int e){
        unordered_map<int,vector<int>> adj;
        for(int i=0;i<e;i++){
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        //call dfs topo sort for all the nodes
        vector<bool> visited(v, false);
        stack<int> st;
        //using this loop we will also include the disconnected components of the graph
        for(int i=0;i<v;i++){
            if(!visited[i]){
                dfs(i,adj,visited,st);
            }
        }
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};