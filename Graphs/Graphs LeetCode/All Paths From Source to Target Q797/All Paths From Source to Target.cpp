#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    void dfs(int node, int target, vector<vector<int>>& graph, vector<int>& path, vector<vector<int>>& ans) {

        if (node == target) {
            ans.push_back(path);
            return;
        }

        for (int neighbor : graph[node]) {
            path.push_back(neighbor);
            dfs(neighbor, target, graph, path, ans);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        //grapgh is adj list 
        vector<vector<int>> ans;
        int n=graph.size();
        vector<int> path;
        path.push_back(0);
        dfs(0, n - 1, graph, path, ans);
        return ans;
        
    }
};