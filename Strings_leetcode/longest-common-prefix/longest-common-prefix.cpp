#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()){
            return "";
        }
        for(int i=0;i<strs[0].length();i++){
            char currentchar=strs[0][i];
            for(int j=0;j<strs.size();j++){
                if(strs[j][i]!=currentchar || i==strs[j].length()){
                    return strs[0].substr(0,i);
                }
            }
        }
        return strs[0];
    }
};