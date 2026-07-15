#include<bits/stdc++.h>
using namespace std;
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*> mp;
    //dfs
    Node* cloneGraph(Node* node) {
        
        if (node == NULL)
            return NULL;

        // If already cloned, return the clone
        if (mp.find(node) != mp.end()){
            return mp[node];
        }
        Node* clone = new Node(node->val);


        mp[node] = clone;

        for (Node* neighbor : node->neighbors) {
            clone->neighbors.push_back(cloneGraph(neighbor));
        }

        return clone;

    }
};