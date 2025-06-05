// https://leetcode.com/problems/lexicographically-smallest-equivalent-string/
// Medium

// Given two strings s1 and s2 of the same length, and a string baseStr, return the lexicographically smallest equivalent string of baseStr based on the equivalence relations defined by s1 and s2.
// The equivalence relations are defined as follows: For each index i, the characters s1[i] and s2[i] are equivalent, meaning that they can be replaced with each other in the baseStr.

#include<vector>
#include<string>
using namespace std;

class Solution {
    int find(vector<int>& parent, int i) {
        if(parent[i] == i)
            return i;
        return parent[i] = find(parent, parent[i]);
    }
    void Union(vector<int>& parent, char a, char b) {
        if(a == b)
            return;
        int idx1 = a - 'a';
        int idx2 = b - 'a';
        int p1 = find(parent, idx1);
        int p2 = find(parent, idx2);
        if(p1 < p2)
            parent[p2] = p1;
        else
            parent[p1] = p2;
    }
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector<int> parent(26);
        for(int i = 0; i < 26; i++)
            parent[i] = i;
        for(int i = 0; i < s1.size(); i++) {
            char a = s1[i];
            char b = s2[i];
            Union(parent, a, b);
        }
        for(char& ch : baseStr)
            ch = find(parent, ch - 'a') + 'a';
        return baseStr;
    }
};