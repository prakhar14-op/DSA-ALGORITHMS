#include<iostream>
#include<algorithm>
using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
        int n=s.length();
        int m=t.length();
        if(n!=m){
            return false;
        }
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        int count[26]={0};
        for(int i=0;i<n;i++){
            count[s[i]-'a']++;
            count[t[i]-'a']--;// ascii ko number me late hai vahi kiya hai now a=0,n=1,c=2 and so on 
        }

        for(int j=0;j<26;j++){
            if(count[j]!=0){
                return false;
            }
        }
        return true;
    }
};