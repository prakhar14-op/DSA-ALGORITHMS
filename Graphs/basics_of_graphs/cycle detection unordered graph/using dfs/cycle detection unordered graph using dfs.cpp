#include<bits/stdc++.h>
using namespace std;
class solution{
private:
    bool iscyclicdfs(int node,unordered_map<int,bool>& visited,unordered_map<int,vector<int>>& adj,int parent){
        visited[node]=true;
        for(auto i:adj[node]){//node ke sare neighbours ke liye loop
            if(!visited[i]){
                bool ans=iscyclicdfs(i,visited,adj,node);
                if(ans==true){
                    return true;
                }
            }
            //and if ap visited ho and parent bhi ho to neglect kar denge 
            // and visited ho and parent na ho to cycle hai
            else if(i!=parent){//neighbour is visited and not parent of current node, then there is a cycle
                return true;
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
                bool ans=iscyclicdfs(i,visited,adj,-1);
                if(ans==true){
                    return "Yes";
                }
            }
        }
        return "No";
    }
};