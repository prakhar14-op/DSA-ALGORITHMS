#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> hash(256,-1);
        int l=0;
        int r=0;
        int max_len=0;
        int n=s.length();
        while(r<n){
            if(hash[s[r]]!=-1){
                //means appeared till now 
                //so checking ki kya ye hamri window ke andar hi appear huya tha
                if(hash[s[r]]>=l){
                    l=hash[s[r]]+1;
                }
            }
            int len=r-l+1;
            max_len=max(max_len,len);
            hash[s[r]]=r;
            r++;
        }
        return max_len;
    }
};