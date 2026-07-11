#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    void makeset(vector<int>& parent,vector<int>& rank,int n){
        for(int i=0;i<n;i++){
            parent[i] = i;
            rank[i] = 0;
        }
    }
    int findparent(int node,vector<int>& parent){
        if(node==parent[node]){
            return node;
        }
        return parent[node]=findparent(parent[node],parent);//path compression
    }
    void unionbyrank(int u,int v,vector<int>& parent,vector<int>& rank){
        u = findparent(u,parent);
        v = findparent(v,parent);
        if(rank[u]<rank[v]){
            parent[u] = v;
        }
        else if(rank[v]<rank[u]){
            parent[v] = u;
        }
        else{
            parent[v] = u;
            rank[u]++;
        }
    }
public:
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        //we are finding the number of rows and numbner of cols 
        int maxrows=0;
        int maxcols=0;
        for(auto it:stones){
            maxrows=max(maxrows,it[0]);
            maxcols=max(maxcols,it[1]);
        }
        //now we know the grid shape
        vector<int> parent(maxrows+maxcols+2);
        vector<int> rank(maxrows+maxcols+2);
        makeset(parent,rank,maxrows+maxcols+2);
        unordered_map<int,int> stoneNodes;

        for(auto it:stones){
            int noderow=it[0];
            int nodecol=it[1]+maxrows+1;
            unionbyrank(noderow,nodecol,parent,rank);
                stoneNodes[noderow] = 1;
                stoneNodes[nodecol] = 1;
        }
        int cnt = 0;

        for(auto it : stoneNodes){

            if(findparent(it.first, parent) == it.first)
                cnt++;
        }
        return n-cnt;
    }
};