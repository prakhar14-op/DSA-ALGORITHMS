#include<bits/stdc++.h>
using namespace std;
class solution{
private:
    bool checkcycledfs(int node,unordered_map<int,bool>& visited,unordered_map<int,bool>& dfsvisited,unordered_map<int,vector<int>>& adj){
        visited[node]=true;
        dfsvisited[node]=true;
        for(auto i:adj[node]){
            if(!visited[i]){
                bool cyclefound=checkcycledfs(i,visited,dfsvisited,adj);
                if(cyclefound){
                    return true;
                }
            }
            //visited hai and sath me dfsvisited bhi hai to cycle hai
            else if(dfsvisited[i]==true){//if neighbour is already visited and also in the current dfs path then there is a cycle
                return true;
            }
        }
        dfsvisited[node]=false;//backtracking
        return false;
    }
public:
    int detectcycle(int n,vector<pair<int,int>>& edges){
        //creating the adj list
        unordered_map<int,vector<int>> adj;
        for(int i=0;i<edges.size();i++){
            int u=edges[i].first;
            int v=edges[i].second;
            adj[u].push_back(v);//since directed graph
        }
        // call dfs for all components
        unordered_map<int,bool> visited;
        unordered_map<int,bool> dfsvisited;
        for(int i=0;i<=n;i++){
            if(!visited[i]){
                bool cyclefound=checkcycledfs(i,visited,dfsvisited,adj);
                if(cyclefound){
                    return true;
                }
            }
        }
        return false;
    } 
};