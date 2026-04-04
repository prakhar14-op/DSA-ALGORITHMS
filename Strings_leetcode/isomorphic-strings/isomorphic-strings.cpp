#include<iostream>
using namespace std;
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n=s.length();
        int m=t.length();
        if(n!=m){
            return false;
        }

        // char currentchar_s='\0';// ese initialize karte hai if empty rakhni ho phle
        // int s_count=0;
        // //s me number of diff strings kitne hai
        // for(int i=0;i<n;i++){
        //     if(s[i]!=currentchar_s){
        //         currentchar_s=s[i];
        //         s_count++;
        //     }
        // }
        // char currentchar_t_='\0';
        // int t_count=0;
        // for(int i=0;i<m;i++){
        //     if(t[i]!=currentchar_t_){
        //         currentchar_t_=t[i];
        //         t_count++;
        //     }
        // }

        // if(t_count==s_count){
        //     return true;
        // }
        // else{
        //     return false;
        // }
        // return false;
        
        char map_s_to_t[256] = {0}; 
        char map_t_to_s[256] = {0}; 

        for (int i = 0; i < s.length(); i++) {
            char char_s = s[i];
            char char_t = t[i];

            if (map_s_to_t[char_s] != 0 && map_s_to_t[char_s] != char_t) {
                return false;
            }
            if (map_t_to_s[char_t] != 0 && map_t_to_s[char_t] != char_s) {
                return false;
            }
            map_s_to_t[char_s] = char_t;
            map_t_to_s[char_t] = char_s;
        }

        return true;
    }
};