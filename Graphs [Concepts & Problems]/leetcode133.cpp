#include<bits/stdc++.h>
using namespace std;

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


class Solution {
    Node* solve(Node* node, vector<Node*>& clones) {
        Node* cloned = new Node(node -> val);
        clones[node -> val] = cloned;
        for(auto neg : node -> neighbors) {
            if(!clones[neg -> val])
                Node* clonedNeighbour = solve(neg, clones);
            cloned -> neighbors.push_back(clones[neg -> val]);
        }
        return cloned;
    }
public:
    Node* cloneGraph(Node* node) {
        if(node == nullptr)
            return nullptr;
        vector<Node*> vis(101, nullptr);
        return solve(node, vis);
    }
};