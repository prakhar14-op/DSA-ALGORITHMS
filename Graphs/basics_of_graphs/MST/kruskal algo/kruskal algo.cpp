#include<bits/stdc++.h>
using namespace std;
class solution{
private:
    bool cmp(vector<int>& a,vector<int>& b){
        return a[2]<b[2];
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
    int minimumst(vector<vector<int>>& edges,int n,int m){
        sort(edges.begin(),edges.end(),cmp);//cmp will sort by weight in ascending order
        vector<int> parent(n);
        vector<int> rank(n);
        makeset(parent,rank,n);
        int minimumcost = 0;
        for(int i=0;i<edges.size();i++){
            int u=findparent(edges[i][0],parent);
            int v=findparent(edges[i][1],parent);

            if(u!=v){
                minimumcost+=edges[i][2];
                unionbyrank(u,v,parent,rank);
            }
        }
        return minimumcost;

    }
     
};