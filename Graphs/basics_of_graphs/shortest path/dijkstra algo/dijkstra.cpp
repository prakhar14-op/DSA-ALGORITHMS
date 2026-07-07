#include<bits/stdc++.h>
using namespace std;
//dijkstra algorithm
class graph{
public:
    vector<int> dijkstra(vector<vector<int>> &vec,int vertices,int edges,int source){
        //creating the adj list 
        unordered_map<int,list<pair<int,int>>> adj;// {node,{neighbour,weight}}
        for(int i=0;i<edges;i++){
            int u=vec[i][0];
            int v=vec[i][1];
            int w=vec[i][2];
            adj[u].push_back(make_pair(v,w));
            adj[v].push_back(make_pair(u,w));

        }
        //distance vector
        vector<int> dist(vertices,INT_MAX);
        //SET
        set<pair<int,int>> st;
        //initially source distance is 0
        dist[source]=0;
        st.insert(make_pair(0,source));
        while(!st.empty()){
            //fetch the top record
            auto top=*(st.begin());
            int nodeDistance=top.first;
            int topNode=top.second;
            st.erase(st.begin());
            //traverse for neighbours
            for(auto neighbour:adj[topNode]){
                if(nodeDistance+neighbour.second<dist[neighbour.first]){
                    //in set updation is not possible so we have to remove the old record and insert new record to simulate updation
                    auto record=st.find(make_pair(dist[neighbour.first],neighbour.first));
                    if(record!=st.end()){
                        //if record found then erase it
                        st.erase(record);
                    }
                    //distance updation
                    dist[neighbour.first]=nodeDistance+neighbour.second;
                    //push in set
                    st.insert(make_pair(dist[neighbour.first],neighbour.first));// here neighbour is traverisng in adj so first is our node and second is our distance
                }
            }
        }
        return dist; 
    }
};