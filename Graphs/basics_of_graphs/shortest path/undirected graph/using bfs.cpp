#include<bits/stdc++.h>
#include<unordered_map>
#include<list>
using namespace std;
class solution{
public:
    vector<int> shortestpath(vector<pair<int,int>> edges,int n,int m, int s, int t){
        //s is the source node and t is the target node 
        // n is the number of nodes and m is the number of edges
        //creating adjacency list
        unordered_map<int,list<int>> adj;
        for(int i=0;i<m;i++){
            int u=edges[i].first;
            int v=edges[i].second;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // do bfs
        unordered_map<int,bool> visited;
        unordered_map<int,int> parent;
        queue<int> q;
        visited[s] = true;
        q.push(s);
        parent[s] = -1;
        while(!q.empty()){
            int frontNode = q.front();
            q.pop();
            for(auto i:adj[frontNode]){
                if(!visited[i]){
                    visited[i] = true;
                    parent[i] = frontNode;
                    q.push(i);
                }
            }
        }
        //prepare the shortest path 
        vector<int> ans;
        int currentnode=t;
        ans.push_back(t);
        //going from target node to source node and pushing the parent of each node into the answer vector
        while(currrentnode!=s){
            currentnode=parent[currentnode];
            ans.push_back(currentnode);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};