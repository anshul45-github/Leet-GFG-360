// Problem Name - Merge Triplets to Form Target Triplet
// Sheet Name - Neetcode 150
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int x = target[0];
        int y = target[1];
        int z = target[2];
        bool X = false;
        bool Y = false;
        bool Z = false;
        for(auto& triplet : triplets) {
            if(triplet[0] == x && triplet[1] <= y && triplet[2] <= z)
                X = true;
            if(triplet[0] <= x && triplet[1] == y && triplet[2] <= z)
                Y = true;
            if(triplet[0] <= x && triplet[1] <= y && triplet[2] == z)
                Z = true;
        }
        return X && Y && Z;
    }
};
