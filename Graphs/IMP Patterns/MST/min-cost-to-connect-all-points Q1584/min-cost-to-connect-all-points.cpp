#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
//cannot be passed directly to sort() so we have to use static 
    static bool cmp(vector<int>& a,vector<int>& b){
        return a[0]<b[0];
    }
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
    int minCostConnectPoints(vector<vector<int>>& points) {
        //kruskal algo 
        int n=points.size(); //number of nodes
        //creaitng the complete graph 
        vector<vector<int>> edges;
        
        vector<bool> vis(false);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int wt=abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                edges.push_back({wt,i,j});
            }
        }
        vector<int> parent(n);
        vector<int> rank(n);
        sort(edges.begin(),edges.end(),cmp);//cmp will sort by weight in ascending order
        makeset(parent,rank,n);
        int minimumcost = 0;
        for(int i=0;i<edges.size();i++){
            int u=findparent(edges[i][1],parent);
            int v=findparent(edges[i][2],parent);

            if(u!=v){
                minimumcost+=edges[i][0];
                unionbyrank(u,v,parent,rank);
            }
        }
        return minimumcost;
    }
};
//do with prims -optimal 