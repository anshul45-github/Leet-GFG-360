// https://leetcode.com/problems/longest-repeating-character-replacement/

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