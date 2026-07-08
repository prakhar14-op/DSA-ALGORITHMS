#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    unordered_map<int,list<pair<int,int>>> adj;
    //adding the edges to the adjacency list
    void addedge(int u,int v,int weight){
        pair<int,int> p=make_pair(v,weight);
        adj[u].push_back(p);
        pair<int,int> q=make_pair(u,weight);
        adj[v].push_back(q);
    }

public:
    int countPaths(int n, vector<vector<int>>& roads) {
        for(auto it:roads){
            addedge(it[0],it[1],it[2]);
        }
        //source is node 0, target is node n-1
        //ways will track the ways like we hvae minstop in Q787
        vector<long long> time(n,LLONG_MAX);
        vector<int> ways(n,0);

        long long MOD=1e9+7;
        set<pair<long long,long long>> st; //{time,node}
        time[0]=0;
        ways[0]=1;
        st.insert({0,0});
        while(!st.empty()){
            auto top=*(st.begin());
            long long top_time=top.first;
            int top_node=top.second;
            st.erase(st.begin());

            //ab yha se neighbour vla traversing
            for(auto it:adj[top_node]){
                if(top_time+it.second<time[it.first]){
                    //checking kya vo phle se to nhi hai set me 
                    auto record=st.find({time[it.first],it.first});
                    if(record!=st.end()){
                        st.erase(record);
                    }
                    //now updation part
                    time[it.first]=top_time+it.second;
                    //since  this is shortes to is node tk pahuchne ke liye from the topnode only 1 path 
                    //so the final path from 0 to this it.first will be same as the path from 0 to topnode
                    ways[it.first]=ways[top_node];
                    st.insert({time[it.first],it.first});
                }
                //if we found a equal length path 
                else if(top_time+it.second==time[it.first]){
                    ways[it.first]=(ways[it.first]+ways[top_node])%MOD;
                }
            }
        }
        return ways[n-1];
        
    }
};

//long long for Initialization: Your time array initialization vector<long long> time(n, 1e9) is also part of the problem. If you initialize it with 1e9 (an int), you are capping your "infinity" value to $10^9$. Any valid path longer than $10^9$ will be incorrectly ignored. Use LLONG_MAX or a significantly larger constant like 1e18