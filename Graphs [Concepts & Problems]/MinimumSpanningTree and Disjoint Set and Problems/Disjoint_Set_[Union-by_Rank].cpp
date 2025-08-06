// Problem attached in sheet does not have rank vector and it is also not possible to define it locally, as we are told to only implement the union and find functions.

#include<bits/stdc++.h>
using namespace std;

class DisjointUnionSets {
    vector<int> rank, parent;

public:
  
    // Constructor to initialize sets
    DisjointUnionSets(int n) {
        rank.resize(n, 0);
        parent.resize(n);

        // Initially, each element is in its own set
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    // Find the representative of the set that x belongs to
    int find(int i) {
        int root = parent[i];
      
        if (parent[root] != root) {
            return parent[i] = find(root);
        }
      
        return root;
    }

    // Union of sets containing x and y
    void unionSets(int x, int y) {
        int xRoot = find(x);
        int yRoot = find(y);

        // If they are in the same set, no need to union
        if (xRoot == yRoot) return;

        // Union by rank
        if (rank[xRoot] < rank[yRoot]) {
            parent[xRoot] = yRoot;
        } else if (rank[yRoot] < rank[xRoot]) {
            parent[yRoot] = xRoot;
        } else {
            parent[yRoot] = xRoot;
            rank[xRoot]++;
        }
    }
};