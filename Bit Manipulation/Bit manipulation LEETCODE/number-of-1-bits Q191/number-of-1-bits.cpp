#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int hammingWeight(int n) {
        int cnt=0;
        while(n>0){
            n=n&(n-1);//removong the right most 1
            cnt++;
        }
        return cnt;
    }
};