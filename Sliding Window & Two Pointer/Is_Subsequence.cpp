// https://leetcode.com/problems/is-subsequence/
// Easy

// Problem Statement:
// Given two strings s and t, return true if s is a subsequence of t, or false otherwise.
// A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters.
// (i.e., "ace" is a subsequence of "abcde" while "aec" is not).

// Example 1:
// Input: s = "abc", t = "ahbgdc"
// Output: true
// Explanation: s is a subsequence of t because we can delete 'h' and 'g' to get "abc".

// Example 2:
// Input: s = "axc", t = "ahbgdc"
// Output: false
// Explanation: s is not a subsequence of t because we cannot delete characters to get "axc".

#include <string>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int idx = 0;
        for(int i = 0; i < t.size(); i++) {
            if(s[idx] == t[i]) {
                idx++;
                if(idx == s.size())
                    return true;
            }
        }
        return idx == s.size();
    }
};