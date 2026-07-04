#include<bits/stdc++.h>
using namespace std;
class solution{
public:
    vector<int> toposort(vector<vector<int>>& edges, int v, int e){
        unordered_map<int,vector<int>> adj;
        for(int i=0;i<e;i++){
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        //create the indegree array
        vector<int> indegree(v,0);
        for(auto it:adj){
            for(auto i:it.second){
                indegree[i]++;
            }
        }

        //create the queue and push all the nodes with indegree 0
        queue<int> q;
        for(int i=0;i<v;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int> ans;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        return ans;
    }
    //do the bfs for all the nodes and also include the disconnected components of the graph
};