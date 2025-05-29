// https://leetcode.com/problems/isomorphic-strings/
// Easy

// Given two strings s and t, determine if they are isomorphic.

// Two strings s and t are isomorphic if the characters in s can be replaced to get t.

// All occurrences of a character must be replaced with another character while preserving the order of characters.

// No two characters may map to the same character, but a character may map to itself.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> mp;
        unordered_set<char> tmp;
        for(int i = 0; i < s.size(); i++) {
            if(!mp.count(s[i])) {
                if(tmp.find(t[i]) != tmp.end())
                    return false;
                mp[s[i]] = t[i];
                tmp.insert(t[i]);
            }
            else if(mp[s[i]] != t[i])
                return false;
        }
        return true;
    }
};