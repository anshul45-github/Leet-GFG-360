// https://leetcode.com/problems/valid-anagram/
// Easy

// Given two strings s and t, return true if t is an anagram of s and false otherwise.

// An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

// Example 1:
// Input: s = "anagram", t = "nagaram"
// Output: true

// Example 2:
// Input: s = "rat", t = "car"
// Output: false

// Example 3:
// Input: s = "a", t = "ab"
// Output: false

// Example 4:
// Input: s = "ab", t = "a"
// Output: false

// Example 5:
// Input: s = "a", t = "a"
// Output: true

// Example 6:
// Input: s = "abc", t = "cba"
// Output: true

// Example 7:
// Input: s = "abc", t = "def"
// Output: false

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagramFollowUp(string s, string t) {
        if(s.size() != t.size())
            return false;
        unordered_map<char, int> mp;
        for(int i = 0; i < s.size(); i++) {
            mp[s[i]]++;
            mp[t[i]]--;
        }
        for(int i = 0; i < s.size(); i++) {
            if(mp[s[i]] != 0)
                return false;
        }
        return true;
    }
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())
            return false;
        vector<int> mp(26, 0);
        for(int i = 0; i < s.size(); i++) {
            mp[s[i] - 'a']++;
            mp[t[i] - 'a']--;
        }
        for(int i = 0; i < 26; i++) {
            if(mp[i] != 0)
                return false;
        }
        return true;
    }
};