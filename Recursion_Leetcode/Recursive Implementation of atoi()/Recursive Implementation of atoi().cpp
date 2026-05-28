#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int myAtoi(string s){
        int i = 0, sign = 1;
        long long result = 0;
        while (s[i] == ' ') {
            i++;
        }
        if (s[i] == '-' || s[i] == '+') {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }
        while (i < s.size() && isdigit(s[i])) {
            result = result * 10 + (s[i] - '0');
            if (result * sign < INT_MIN) {
                return INT_MIN;
            }
            if (result * sign > INT_MAX) {
                return INT_MAX;
            }
            i++;
        }
        return result * sign;

    }
};

//recursive approach
class Solution {
public:
    int myAtoi(string s) {
        int i = 0, sign = 1;
        long long result = 0;
        while (s[i] == ' ') {
            i++;
        }
        if (s[i] == '-' || s[i] == '+') {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }
        return helper(s, i, sign, result);
    }
    
private:
    int helper(string s, int i, int sign, long long result) {
        if (i >= s.size() || !isdigit(s[i])) {
            return result * sign;
        }
        result = result * 10 + (s[i] - '0');
        if (result * sign < INT_MIN) {
            return INT_MIN;
        }
        if (result * sign > INT_MAX) {
            return INT_MAX;
        }
        return helper(s, i + 1, sign, result);
    }  
};