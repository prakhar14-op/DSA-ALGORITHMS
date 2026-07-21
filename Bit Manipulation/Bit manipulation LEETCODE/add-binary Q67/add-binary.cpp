#include<bits/stdc++.h>
using namespace std;
class Solution {
    //Instead of writing loops to count or check bits, std::bitset gives you incredibly fast built-in functions:
    //.any(): Returns true if at least one bit is set to 1..
    //none(): Returns true if all bits are set to 0.
    //.count(): Returns the exact number of 1 bits (very fast).
    //.size(): Returns the total number of bits in the bitset.
    //.flip(): Inverts all bits (0 becomes 1, 1 becomes 0).
    //.to_string(): Converts the bitset back into a readable C++ std::string
private:
    string convert2binary(int n){
        if (n == 0) return "0";
        string res="";
        while(n>0){
            if(n%2==1){
                res+='1';
            }
            else{
                res+='0';
            }
            n = n / 2;
        }
        
        reverse(res.begin(), res.end()); 
        return res;
    }
    int convert2decimal(string x){
        int len=x.length();
        int num=0;
        long long p2=1;
        for(int i=len-1;i>=0;i--){
            if(x[i]=='1'){
                num=num+p2;
            }
            p2=p2*2;
        }
        return num;
    }
public:
    string addBinary(string a, string b) {
        // int x=convert2decimal(a);
        // int y=convert2decimal(b);
        // int ans=x+y;
        // string fa=convert2binary(ans);
        // return fa;

        const int MAX_SIZE = 10005;
        bitset<MAX_SIZE> x(a);
        bitset<MAX_SIZE> y(b);

        // Run the bit manipulation half-adder algorithm
        while (y.any()) { // .any() checks if there are still any carry bits left
            bitset<MAX_SIZE> ans = x ^ y;       // XOR finds sum bits without carry
            bitset<MAX_SIZE> carry = (x & y) << 1; // AND + shift finds carry bits
            
            x = ans;
            y = carry;
        }
        string fa = x.to_string();
        //searches your string from left to right and returns the index of the very first character that does not match the characters you passed into it.
        size_t first_one = fa.find_first_not_of('0');
        
        // If there are no 1s found, it means the answer is just "0"
        if (first_one == string::npos) {
            return "0";
        }
        return fa.substr(first_one);
    }
};