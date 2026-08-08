#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        //whose indegrees is 0 those will be in our ans for sure 
        //now we will check those nodes are covering all the nodes using the adj list 
        vector<int> indegree(n);
        vector<vector<int>> adj(n);
        for(auto it:edges){
            int from=it[0];
            int to=it[1];
            indegree[to]++;
        }
        //now finding the node having the indegree=0
        vector<int> result;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                result.push_back(i);
            }
        }
        return result;
    }
};