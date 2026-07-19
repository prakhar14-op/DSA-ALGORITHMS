#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        //step 1 sort both g and s
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int n=g.size();
        int m=s.size();
        int r=0;
        int l=0;
        while(r < n && l<m){
            if(g[r]<=s[l]){
                //can satisfy that child
                r=r+1;
            }
            l=l+1;
        }
        return r;
    }
};