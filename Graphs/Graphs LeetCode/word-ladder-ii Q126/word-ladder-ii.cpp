#include<bits/stdc++.h>
using namespace std;
class Solution {
private: 
    unordered_map<string, int> mpp; 
    vector<vector<string>> ans;

    
    void dfs(string word, string& beginWord, vector<string>& path) {
        // The Base Case
        if (word == beginWord) {
            vector<string> correctPath = path;
            reverse(correctPath.begin(), correctPath.end());
            ans.push_back(correctPath);
            return;
        }

        int currentSteps = mpp[word];
        string originalWord = word;

        for (int i = 0; i < word.length(); i++) {
            char originalChar = word[i];
            
            for (char ch = 'a'; ch <= 'z'; ch++) {
                word[i] = ch;

                if (mpp.find(word) != mpp.end() && mpp[word] == currentSteps - 1) {
                    path.push_back(word);

                    dfs(word, beginWord, path);
                    path.pop_back(); 
                }
            }
            word[i] = originalChar; 
        }
    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        mpp.clear();
        ans.clear();

        unordered_set<string> st(wordList.begin(), wordList.end());
        queue<string> q; 

        //  STAGE 1: THE BFS 
        q.push(beginWord);
        mpp[beginWord] = 1;
        st.erase(beginWord);

        while(!q.empty()){
            string word = q.front();
            int steps = mpp[word]; 
            q.pop();

            string originalWord = word;
            for(int i = 0; i < word.length(); i++){
                char original = word[i];
                
                for(char ch = 'a'; ch <= 'z'; ch++){
                    word[i] = ch;
                    
                    if(st.find(word) != st.end()){
                        st.erase(word); 
                        q.push(word);
                        mpp[word] = steps + 1;
                    }
                }
                word[i] = original; 
            }
        }

        if (mpp.find(endWord) != mpp.end()) {
            vector<string> path;
            path.push_back(endWord); 
            dfs(endWord, beginWord, path);
        }

        return ans;

    }
};