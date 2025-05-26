//https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/
// Medium

// Given a string s consisting only of characters 'a', 'b', and 'c'.

// Return the number of substrings containing at least one occurrence of all these characters 'a', 'b', and 'c'.

// A substring is a contiguous sequence of characters within the string.

// Example 1:
// Input: s = "abcabc"
// Output: 10
// Explanation: The substrings containing at least one occurrence of all characters are:
// "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc", and "abc".

// Example 2:
// Input: s = "aaacb"
// Output: 3
// Explanation: The substrings containing at least one occurrence of all characters are:
// "aabcb", "aaacb", and "acb".

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char, int> mp;
        int l = 0;
        int r = 0;
        int zeroOccurrence = 0;
        while(r < s.size()) {
            mp[s[r]]++;
            while(mp['a'] && mp['b'] && mp['c']) {
                mp[s[l]]--;
                l++;
            }
            zeroOccurrence += r - l + 1;
            r++;
        }
        long long total = s.size() * (s.size() + 1) / 2;
        return total - zeroOccurrence;
    }
};