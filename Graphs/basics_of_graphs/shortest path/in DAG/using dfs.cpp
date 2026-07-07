#include<bits/stdc++.h>
#include <unordered_map>
using namespace std;
class Graph{
private:
    unordered_map<int,list<pair<int,int>>> adj;
    //adding the edges to the adjacency list
    void addedge(int u,int v,int weight){
        pair<int,int> p=make_pair(v,weight);
        adj[u].push_back(p);
    }


    //PRINTING THE ADJACENCY LIST
    void printadj(){
        for(auto i:adj){
            cout<<i.first<<"->";
            for(auto j:i.second){
                cout<<"("<<j.first<<","<<j.second<<")";
            }
            cout<<endl;
        }
    }


    


    void dfs(int node,unordered_map<int,bool> &visited,stack<int> &st,unordered_map<int,list<pair<int,int>>> &adj){
        visited[node]=true;
        for(auto i:adj[node]){
            if(!visited[i.first]){
                dfs(i.first,visited,st,adj);
            }
        }
        st.push(node);
    }
    void shortestpath(int src,vector<int> &dist,stack<int> &st,unordered_map<int,list<pair<int,int>>> &adj){
        dist[src]=0;
        while(!st.empty()){
            int top=st.top();
            st.pop();
            if(dist[top]!=INT_MAX){
                for(auto i:adj[top]){
                    if(dist[top]+i.second<dist[i.first]){
                        dist[i.first]=dist[top]+i.second;
                    }
                }
            }
        }
    }
public:
    int main(){
        Graph g;
        g.addedge(0,1,5);
        g.addedge(0,2,3);
        g.addedge(1,3,6);
        g.addedge(1,2,2);
        g.addedge(2,4,4);
        g.addedge(2,5,2);
        g.addedge(2,3,7);
        g.addedge(3,5,-1);
        g.addedge(4,5,-2);
        g.printadj();
        //topo sort 
        unordered_map<int,bool> visited;
        stack<int> st;
        for(int i=0;i<adj.size();i++){
            if(!visited[i]){
                dfs(i,visited,st,adj);
            }
        }

        //now we have the stack ready and we can find the shortest path from the source node to all other nodes in the graph
        g.shortestpath(src,dist,st,adj);

    }
};