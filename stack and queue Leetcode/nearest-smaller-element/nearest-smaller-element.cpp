#include<bits/stdc++.h>
using namespace std;
int* prevSmaller(int* A, int n1, int *len1) {
    int* prevSmaller(int* A, int n1, int *len1) {
    stack<int> st;
    vector<int> ans(len1,-1);
    for(int i=0;i<n;i++){
        while(!st.empty() && st.top()>=A[i]){
            st.pop();
        }
        if(!st.empty()){
            ans[i]=st.top();
        }
        st.push();
    }
    return ans;
}
