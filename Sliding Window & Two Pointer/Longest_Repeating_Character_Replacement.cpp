// https://leetcode.com/problems/longest-repeating-character-replacement/
// 424. Longest Repeating Character Replacement
// Medium

#include<bits/stdc++.h>
using namespace std;

class Solution {
    int max(int a, int b) {
        return a >= b ? a : b;
    }
public:
    int characterReplacement(string s, int k) {
        int start = 0;
        int maxAns = 0;
        unordered_map<char, int> mp;
        int maxFreq = 0;
        for(int end = 0; end < s.size(); end++) {
            mp[s[end]]++;
            if(mp[s[end]] > maxFreq)
                maxFreq = mp[s[end]];
            while(end - start + 1 - maxFreq > k) {
                mp[s[start]]--;
                start++;
                maxFreq = 0;
                for(char ch = 'A'; ch <= 'Z'; ch++) {
                    maxFreq = max(maxFreq, mp[ch]);
                }
            }
            maxAns = max(maxAns, end - start + 1);
        }
        return maxAns;
    }
};
