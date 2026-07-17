#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    //bina static ke kam nhi chalega 
    static bool cmp(vector<int>& a,vector<int>& b){
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
    int getMSTWeight(int n, vector<vector<int>>& edges, int excludeEdge, int includeEdge) {
        vector<int> parent(n);
        vector<int> rank(n);
        makeset(parent, rank, n);
        
        int cost = 0;
        int edgesAdded = 0; 

        if (includeEdge != -1) {
            int u = findparent(edges[includeEdge][0], parent);
            int v = findparent(edges[includeEdge][1], parent);
            
            if (u != v) {
                unionbyrank(u, v, parent, rank);
                cost += edges[includeEdge][2];
                edgesAdded++;
            }
        }

        // Standard Kruskal's Loop
        for(int i = 0; i < edges.size(); i++) {
            // Test A: Force Exclude an Edge (for critical checks)
            if (i == excludeEdge) continue; 

            int u = findparent(edges[i][0], parent);
            int v = findparent(edges[i][1], parent);

            if (u != v) {
                cost += edges[i][2];
                unionbyrank(u, v, parent, rank);
                edgesAdded++;
            }
        }

        // Did the graph shatter?
        // A valid MST MUST have exactly n - 1 edges.
        if (edgesAdded != n - 1) {
            return 1e9; // Return infinity if graph is disconnected
        }

        return cost;
    }
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        //number of edges n 
        //step 1 using kruskal find the mst cost 

        //before sorting preserving the edge number 
        for(int i = 0; i < edges.size(); i++){
            edges[i].push_back(i); // Now edges[i][3] holds the original index!
        }
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
        //now we know the min cost so 
        //To find if one edge is critical, delete that edge and re-run the MST algorithm and see if the weight of the new MST increases.
        //step 2
        vector<int> critical;
        vector<int> pseudo_critical;
        for (int i = 0; i < edges.size(); i++) {
            
            // (Exclude it and see if cost goes up)
            if (getMSTWeight(n, edges, i, -1) > minimumcost) {
                critical.push_back(edges[i][3]); // Push original index
            } 
            // (Force include it and see if cost stays the same)
            else if (getMSTWeight(n, edges, -1, i) == minimumcost) {
                pseudo_critical.push_back(edges[i][3]); // Push original index
            }
        }

        return {critical, pseudo_critical};


    }
};