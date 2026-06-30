#include<bits/stdc++.h>
using namespace std;
//making graph from adjacency list
class graph{
    unordered_map<int,vector<int>> adj;
public:
    void addedge(int u, int v, bool direction){
        adj[u].push_back(v);
        if(direction==0){
            adj[v].push_back(u);
        }
    }
    void printadjlist(){
        for(auto i:adj){
            cout<<i.first<<"->";
            for(int j=0;j<i.second.size();j++){
                cout<<i.second[j]<<" ";
            }
            cout<<endl;
        }
    }
};

int main(){
    int n;
    cout<<"Enter the number of nodes: ";
    cin>>n;
    int m;
    cout<<"Enter the number of edges: ";
    cin>>m;
    graph g;
    for(int i=0;i<m;i++){
        int u,v;
        cout<<"Enter the edge: ";
        cin>>u>>v;
        g.addedge(u,v,0);
    }
    g.printadjlist();
}