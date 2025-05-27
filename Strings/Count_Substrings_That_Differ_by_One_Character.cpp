// https://leetcode.com/problems/count-substrings-that-differ-by-one-character/
// Medium

// Given two strings s and t, return the number of substrings that differ by exactly one character.

// A substring is a contiguous sequence of characters within a string.

// Example 1:
// Input: s = "aba", t = "baba"
// Output: 6

// Example 2:
// Input: s = "ab", t = "bb"
// Output: 3

// Example 3:
// Input: s = "a", t = "a"
// Output: 0

// Constraints:
// 1 <= s.length, t.length <= 100
// s and t consist of lowercase English letters.

#include<string>
using namespace std;

class Solution {
public:
    int countSubstrings(string s, string t) {
        int res = 0;
        for(int i = 0; i < s.size(); i++) {
            for(int j = 0; j < t.size(); j++) {
                if(s[i] != t[j]) {
                    int l = 1;
                    int r = 1;
                    while(i - l >= 0 && j - l >= 0 && s[i - l] == t[j - l])
                        l++;
                    while(i + r < s.size() && j + r < t.size() && s[i + r] == t[j + r])
                        r++;
                    res += r * l;
                }
            }
        }
        return res;
    }
};