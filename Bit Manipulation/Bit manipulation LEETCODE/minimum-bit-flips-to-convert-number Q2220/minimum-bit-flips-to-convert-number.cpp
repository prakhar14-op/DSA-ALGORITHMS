#include<bits/stdc++.h>
using namespace std;
class Solution {
// private:
//     string convert2binary(int n){
//         string res="";
//         while(n!=1){
//             if(n%2==1){
//                 res+='1';
//             }
//             else{
//                 res+='0';
//             }
//         }
//         return res;
//     }
public:
    int minBitFlips(int start, int goal) {
        // string s=convert2binary(start);
        // string g=convert2binary(goal);
        // int sl=s.length();
        // int gl=g.length();
        // int ans=0;
        // for(int i=0;i<sl;i++){
        //     if(s[i]!=g[i]){
        //         ans++;
        //     }
        // }
        // return ans;
        int ans=start^goal;
        int count=0;
        while(ans>0){
            ans=ans&(ans-1);
            count++;
        }
        return count;
    }
};