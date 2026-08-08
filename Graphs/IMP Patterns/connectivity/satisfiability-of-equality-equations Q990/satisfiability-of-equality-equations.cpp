#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    bool cmp(vector<int>& a,vector<int>& b){
        return a[2]<b[2];
    }
    void makeset(vector<int>& parent,vector<int>& rank,int n){
        for(int i=0;i<n;i++){
            rank[i] = 0;
            
        }
        for(int i=0;i<26;i++){
            parent[i]=i;
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
    bool equationsPossible(vector<string>& equations) {
        //unit weights 
        vector<int> parent(26);
        vector<int> rank(26);
        makeset(parent,rank,26);

        //now iterating throgh the equation 
        int n=equations.size();
        for(string eq:equations){
            if(eq[1]=='='){
                int u = eq[0] - 'a';
                int v = eq[3] - 'a';
                unionbyrank(u,v,parent,rank);
            }
        }
        //now iterating and cheking all != equations
        for(string eq:equations){
            if(eq[1]=='!'){
                int u = eq[0] - 'a';
                int v = eq[3] - 'a';
                //this != eqatiion is wrong
                if(findparent(u,parent)==findparent(v,parent)){
                    return false;
                }
            }
        }
        return true;


    }
};