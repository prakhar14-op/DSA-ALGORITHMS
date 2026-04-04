#include<iostream>
#include<algorithm>
using namespace std;
class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        int slow = 0; 
        for (int fast = 0; fast < n; ++fast) { 
            if (s[fast] != ' ') {

                if (slow != 0) {
                    s[slow] = ' ';
                    slow++;
                }
                
                // Copy the entire word over
                while (fast < n && s[fast] != ' ') {
                    s[slow] = s[fast];
                    slow++;
                    fast++;
                }
            }
        }

        s.resize(slow);
        reverse(s.begin(), s.end());
        int start = 0; 
        for (int i = 0; i <= s.length(); ++i) {
            if (i == s.length() || s[i] == ' ') {
                reverse(s.begin() + start, s.begin() + i);
                start = i + 1; 
            }
        }
        
        return s;
    }

};