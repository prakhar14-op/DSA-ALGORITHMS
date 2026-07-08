#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    unordered_map<int,list<pair<int,int>>> adj;
    //adding the edges to the adjacency list
    void addedge(int u,int v,int weight){
        pair<int,int> p=make_pair(v,weight);
        adj[u].push_back(p);
    }
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        //creating the adj list for weighted graph
        for(auto it:flights){
            addedge(it[0],it[1],it[2]);
        }

        //now using the dijkstra since ye directed cyclic graph
        //ditance ko track na kar ke ham min stops us node tk ke track kar rhe and distance ko us path me bs add kar ke set me dalte ja rhe (see the last for loop)
        vector<int> minstops(n,1e9);
        minstops[src]=0;
        vector<int> dist(n,1e9);
        dist[src]=0;

        //we also have to track the number of stop we have done 
        set<pair<int,pair<int,int>>> st; //{weight,{node,stops till now}}
        
        st.insert({0,{src,0}});
        while(!st.empty()){
            auto top=*(st.begin());
            int cost=top.first;
            int topnode=top.second.first;
            int curr_stop=top.second.second;
            st.erase(st.begin());

            if(topnode==dst){
                return cost;
            }
            //if we exced the stop limit skip this node and since we have erase it we will look to the previous node remaining in the set 
            if(curr_stop>k){
                continue;
            }
            //yha tk aa gye means no limit reached
            //now going to neighbours
            for(auto it:adj[topnode]){
                int neig_node=it.first;
                int neig_cost=it.second;

                if(cost + neig_cost < dist[neig_node] || curr_stop+1<minstops[neig_node]){
                    minstops[neig_node]=curr_stop+1;
                    dist[neig_node]=cost + neig_cost;
                    st.insert({cost+neig_cost,{neig_node,curr_stop+1}});
                }

            }
        }
        return -1;
    }
};