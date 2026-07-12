#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    void makeset(vector<int>& parent,vector<int>& rank,vector<int>& size,int n){
        for(int i=0;i<n;i++){
            parent[i] = i;
            rank[i] = 0;
            size[i] = 1;
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
    void unionBySize(int u, int v, vector<int>& parent, vector<int>& size) {
        u = findparent(u, parent);
        v = findparent(v, parent);

        if (u == v)
            return;

        if (size[u] < size[v]) {
            parent[u] = v;
            size[v] += size[u];
        } else {
            parent[v] = u;
            size[u] += size[v];
        }
    }
    bool isvalid(int newr,int newc,int n){
        return newr>=0 && newr<n && newc>=0 && newc<n;
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<int> parent(n*n);
        vector<int> rank(n*n);
        vector<int> size(n*n,1);
        int mx=0;
        makeset(parent,rank,size,n*n);
        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                if(grid[row][col]==0){
                    continue;
                    //not merging it 
                }
                int dr[]={-1,0,1,0};
                int dc[]={0,-1,0,1};
                //now going to the neigh having 1 and merging it 
                for(int ind=0;ind<4;ind++){
                    int newr=row+dr[ind];
                    int newc=col+dc[ind];
                    if(isvalid(newr,newc,n) && grid[newr][newc]==1){
                        int nodeno=row*n+col;
                        int adjnodeno=newr*n+newc;
                        unionBySize(nodeno,adjnodeno,parent,size);
                    }
                }
            }
        }
            //step 2
            
            for(int row=0;row<n;row++){
                for(int col=0;col<n;col++){
                    if(grid[row][col]==1){
                        continue;
                        //not merging it 
                    }
                    int dr[]={-1,0,1,0};
                    int dc[]={0,-1,0,1};
                    set<int> components;
                    //now going to the neigh having 1 and merging it 
                    for(int ind=0;ind<4;ind++){
                        int newr=row+dr[ind];
                        int newc=col+dc[ind];
                        
                        if(isvalid(newr,newc,n)){
                            if(grid[newr][newc]==1){
                                components.insert(findparent(newr*n+newc,parent));

                            }
                        }
                    }
                    int sizetotal=0;
                    for(auto it:components){
                        sizetotal += size[it];
                    }
                    mx=max(mx,sizetotal+1);
                }
            }
            for(int cellno=0;cellno<n*n;cellno++){
                mx=max(mx,size[findparent(cellno,parent)]);
            }    
        
        return mx;
    }
};