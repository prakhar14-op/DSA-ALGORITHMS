#include<bits/stdc++.h>
using namespace std;
class solution{
private:
    bool iscyclicbfs(int src,unordered_map<int,bool>& visited,unordered_map<int,vector<int>>& adj){
        unordered_map<int,int> parent;
        parent[src]=-1;
        queue<int> q;
        q.push(src);
        while(!q.empty()){
            int frontnode=q.front();
            q.pop();
            for(auto i:adj[frontnode]){
                if(visited[i]==true && i!=parent[frontnode]){
                    return true;
                }
                else if(!visited[i]){
                    visited[i]=true;
                    q.push(i);
                    parent[i]=frontnode;
                }
            }
        }
        return false;
    }
public:
    string cycledetection(vector<vector<int>>& edges, int n,int m){
        //n no of nodes
        // m no of edges
        //creating the adj list 
        unordered_map<int,vector<int>> adj;
        for(int i=0;i<m;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u) ;
        }

        // to handle disconnected graogh we will loop over all the nodes and check if they are visited or not
        unordered_map<int,bool> visited;
        for(int i=0;i<n;i++){
            visited[i]=false;
        }
        for(int i=0;i<n;i++){
            if(!visited[i]){
                visited[i]=true;
                bool ans=iscyclicbfs(i,visited,adj);
                if(ans==true){
                    return "Yes";
                }
            }
        }
        return "No";
    }
};