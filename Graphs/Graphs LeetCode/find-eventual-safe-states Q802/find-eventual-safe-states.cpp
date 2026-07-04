#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        //applying the kahn's algo
        // reversing the graph
        int n=graph.size();
        vector<vector<int>> revgraph(n);
        vector<int> indegree(n,0);
        for(int i=0;i<n;i++){
            for(int j:graph[i]){
                revgraph[j].push_back(i);
                //updating th indegree also 
                indegree[i]++;
            }  
        }
        //now exact same kahn's algo
        //creating the queue 
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int> ans;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto it:revgraph[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};