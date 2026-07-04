#include<bits/stdc++.h>
using namespace std;
class Solution {
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
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //if cycle exist means deadlock lag jayega
        //in prerequisites [a,b] means b to a edge
        //creating the adj list
        unordered_map<int,vector<int>> adj;
        int n=prerequisites.size();
        for(int i=0;i<n;i++){
            int u=prerequisites[i][0];
            int v=prerequisites[i][1];
            adj[u].push_back(v);
        }
        unordered_map<int,bool> visited;
        unordered_map<int,bool> dfsvisited;
        for(int i=0;i<numCourses;i++){
            if(!visited[i]){
                bool cyclefound=checkcycledfs(i,visited,dfsvisited,adj);
                if(cyclefound){
                    return false;
                }
            }
        }
        return true;

    }
};