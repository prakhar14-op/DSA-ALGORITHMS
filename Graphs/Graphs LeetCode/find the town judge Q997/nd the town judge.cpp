#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        //it is about the indegree and out degree
        // the judge is the one with 0 outdegree and n indegree
        //hame yha adj list banae ki zarurat nhi vo hame batati ki konse nodes se connected hai but we just want number na ki kon juda hai
        // vector<int> indegree(n+1,0);
        // vector<int> outdegree(n+1,0);
        // for(auto i:trust){
        //     outdegree[i[0]]++;
        //     indegree[i[1]]++;
        // }
        // //we have a proper indegree and outdegree
        // // now finding the judge
        // for(int i=1;i<n+1;i++){
        //     if(indegree[i]==n-1 && outdegree[i]==0){
        //         return i;
        //     }
        // }
        // return -1;


        //optimal 
        vector<int> trustscore(n+1,0);
        for(auto i:trust){
            trustscore[i[0]]--;
            trustscore[i[1]]++;
        }
        for(int i=1;i<n+1;i++){
            if(trustscore[i]==n-1){
                return i;
            }
        }
        return -1;
    }
};