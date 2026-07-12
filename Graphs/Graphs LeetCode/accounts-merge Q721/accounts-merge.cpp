#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        vector<int> parent(n);
        vector<int> rank(n);
        makeset(parent,rank,n);
        unordered_map<string,int> mapmailnode;
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string mail=accounts[i][j];
                if(mapmailnode.find(mail)==mapmailnode.end()){
                    mapmailnode[mail]=i;
                }
                else{
                    //and if ohle se kahi link hai to ab its time to merge 
                    unionbyrank(i,mapmailnode[mail],parent,rank);
                }
            }
        }
        // Group emails by parent account
        vector<string> mergedMail[n];//doubt

        for (auto it : mapmailnode) {
            string mail = it.first;
            int node = it.second;

            int parentNode = findparent(node, parent);
            mergedMail[parentNode].push_back(mail);
        }
        vector<vector<string>> ans;

        for (int i = 0; i < n; i++) {
            if (mergedMail[i].empty())
                continue;

            sort(mergedMail[i].begin(), mergedMail[i].end());

            vector<string> temp;
            temp.push_back(accounts[i][0]);

            for (string &mail : mergedMail[i]){
                temp.push_back(mail);
            }
            ans.push_back(temp);
        }

        return ans;
    }
};