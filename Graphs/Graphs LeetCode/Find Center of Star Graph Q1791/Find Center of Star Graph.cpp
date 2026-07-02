#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        // Is the first node of edge 0 equal to either node of edge 1
        if (edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1]) {
            return edges[0][0];
        } 
        // If not, it MUST be the second node of edge 0.
        return edges[0][1];
    }
};