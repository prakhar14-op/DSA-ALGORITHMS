#include<bits/stdc++.h>
using namespace std;
class solution{
    vector<pair<pair<int,int>,int>> calculatePrimsMST(int n,int m, vector<pair<pair<int,int>,int>> &edges){
        //creating the adj list 
        //n is number of nodes 
        //m is number of edges
        unordered_map<int,list<pair<int,int>>> adj;
        for(auto it: edges){
            int u = it.first.first;
            int v = it.first.second;
            int wt = it.second;
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        vector<int> key(n+1,1e9);//n+1 bcoz indix ko node se rep kar rhe index 1 node 1 ko rep kar rha 
        vector<int> parent(n+1,-1);
        vector<bool> mst(n+1,false);
        key[1] = 0;
        parent[1] = -1;
        for(int i=1;i<n;i++){
            int mini = INT_MAX;// to track the min of the key array and find the min node
            int u;
            for(int v=1;v<=n;v++){
                if(mst[v]==false && key[v]<mini){
                    u = v;
                    mini = key[v];
                }
            }
            mst[u] = true;
            for(auto it: adj[u]){
                int v = it.first;
                int wt = it.second;
                if(mst[v]==false && wt<key[v]){
                    parent[v] = u;
                    key[v] = wt;
                }
            }
        }
        vector<pair<pair<int,int>,int>> result;
        for(int i=2;i<=n;i++){
            result.push_back({{parent[i],i},key[i]});//{{u->v},wt}
        }
        return result;
    } 
};