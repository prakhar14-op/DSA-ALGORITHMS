#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        //we will make the connection 2D to mark those nodes which are connected  and simultaiosly track the degree of each node 
        //then we wil take all the nodes with th elargets and the second largest degree and check pair of those nodes 
        //we dont need adj list here
        vector<vector<bool>> connected(n,vector<bool>(n,false));
        vector<int> degree(n,0);
        for(auto it:roads){
            int a=it[0];
            int b=it[1];
            degree[a]++;
            degree[b]++;
            connected[a][b]=true;
            connected[b][a]=true;
        }
        //now just finding the largest and second largest degree 
        int max1=0;
        int max2=0;
        for(int d:degree){
            if(d>max1){
                max2=max1;
                max1=d;
            }
            else if(d>max2 && d<max1){
                max2=d;
            }
        }
        //making group of the nodes having the max degree
        vector<int> group1,group2;
        for(int i=0;i<n;i++){
            if(degree[i]==max1){
                group1.push_back(i);
            }
            else if(degree[i]==max2){
                group2.push_back(i);
            }
        }
        if(group1.size()>1){
            for(int i=0;i<group1.size();i++){
                for(int j=i+1;j<group1.size();j++){
                    if(!connected[group1[i]][group1[j]]){
                        return 2*max1;
                    }

                }
            }
            return 2*max1-1;
        }
        //we dont have 2 or more nodes having the max degree so now checkinng Only one unique node has the absolute maximum degree
        int unique=group1[0];
        for(int it:group2){
            if(!connected[unique][it]){
                return max1+max2;
            }
        }
        return max1+max2-1;
    }
};