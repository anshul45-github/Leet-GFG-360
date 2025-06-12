// https://leetcode.com/problems/longest-repeating-character-replacement/
// Medium

// You are given a string s and an integer k. You can replace any character of the string with any other uppercase English character up to k times.

// Find the length of the longest substring containing the same letter you can get after performing at most k replacements.

// Note: Both the string's length and k will not exceed 10^5.

// Example 1:
// Input: s = "ABAB", k = 2
// Output: 4
// Explanation: Replace the two 'A's with two 'B's or vice versa.

// Example 2:
// Input: s = "AABABBA", k = 1
// Output: 4

// Example 3:
// Input: s = "AABABBA", k = 2
// Output: 5

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0;
        int maxlen = 0;
        int maxFreq = 0;
        unordered_map<char, int> mp;
        for(int r = 0; r < s.size(); r++) {
            maxFreq = max(maxFreq, ++mp[s[r]]);
            while(r - l + 1 - maxFreq > k) {
                mp[s[l]]--;
                l++;
                for(char ch = 'A'; ch <= 'Z'; ch++)
                    maxFreq = max(maxFreq, mp[ch]);
            }
            maxlen = max(maxlen, r - l + 1);
        }
        return maxlen;
    }
};