// Problem attached in sheet does not have size vector and it is also not possible to define it locally, as we are told to only implement the union and find functions.

#include<bits/stdc++.h>
using namespace std;

class UnionFind {
    vector<int> Parent;
    vector<int> Size;
public:
    UnionFind(int n) {      
        Parent.resize(n);
        for (int i = 0; i < n; i++) {
            Parent[i] = i;
        }

        // Initialize Size array with 1s
        Size.resize(n, 1);
    }

    // Function to find the representative (or the root
    // node) for the set that includes i
    int find(int i) {
        int root = Parent[i];
      
        if (Parent[root] != root) {
            return Parent[i] = find(root);
        }
      
        return root;
    }

    // Unites the set that includes i and the set that
    // includes j by size
    void unionBySize(int i, int j) {
      
        // Find the representatives (or the root nodes) for
        // the set that includes i
        int irep = find(i);

        // And do the same for the set that includes j
        int jrep = find(j);

        // Elements are in the same set, no need to unite
        // anything.
        if (irep == jrep)
            return;

        // Get the size of i’s tree
        int isize = Size[irep];

        // Get the size of j’s tree
        int jsize = Size[jrep];

        // If i’s size is less than j’s size
        if (isize < jsize) {
          
            // Then move i under j
            Parent[irep] = jrep;

            // Increment j's size by i's size
            Size[jrep] += Size[irep];
        }
        // Else if j’s size is less than i’s size
        else {
            // Then move j under i
            Parent[jrep] = irep;

            // Increment i's size by j's size
            Size[irep] += Size[jrep];
        }
    }
};