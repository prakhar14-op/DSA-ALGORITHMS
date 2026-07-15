#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    double dfs(string start,string target,unordered_set<string>& visited,unordered_map<string, vector<pair<string,double>>>& graph){
        visited.insert(start);
        if(start==target){
            return 1.0;
        }
        for(auto it : graph[start]){
            string next = it.first;
            double weight = it.second;
            if(visited.count(next)){
                continue;
            }
            double ans = dfs(next,target,visited,graph);
            if(ans != -1.0){
                return weight * ans;
            }
        }
        return -1;
        
    }
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        //creating the graph
        unordered_map<string, vector<pair<string,double>>> graph;
        int i=0;
        for(auto it:equations){
            string node1=it[0];
            string node2=it[1];
            double weight=values[i];
            i++;
            graph[node1].push_back({node2,weight});
            graph[node2].push_back({node1,1.0/weight});
        }
        //now the graph is complete 
        //we will traverse the queries and our ans will be Ci to Di path and uske path me sare weights ka multiplication
        //dfs
        vector<double> ans;
        for(auto it:queries){
            unordered_set<string> visited;
            string start=it[0];
            string target=it[1];
            if(graph.find(start) == graph.end() ||
               graph.find(target) == graph.end()){

                ans.push_back(-1.0);
                continue;
            }
            ans.push_back(dfs(start,target,visited,graph));

        }
        return ans;

    }
};