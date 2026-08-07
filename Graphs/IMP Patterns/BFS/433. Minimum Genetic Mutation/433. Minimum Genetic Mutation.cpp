#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        queue<pair<string,int>> q;
        //intitially steps =0 since here steps are rep number of mutation performed but when we are at the startgene there is no mutation done 
        q.push({startGene,0});
        unordered_set<string> st(bank.begin(),bank.end());
        st.erase(startGene);
        while(!q.empty()){
            auto f=q.front();
            string word=f.first;
            int steps=f.second;
            q.pop();
            if(word==endGene){
                return steps;
            }
            for(int i=0;i<word.length();i++){
                char original=word[i];
                for(char ch:{'A','C','G','T'}){
                    word[i]=ch;
                    if(st.find(word)!=st.end()){
                        st.erase(word);
                        q.push({word,steps+1});
                    }
                }
                word[i]=original;
            }
        }
        return -1;
    }
};