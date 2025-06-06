// https://leetcode.com/problems/longest-repeating-character-replacement/
// 424. Longest Repeating Character Replacement
// Medium

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int start = 0;
        int maxAns = 0;
        int maxFreq = 0;
        unordered_map<char, int> mp;
        for(int end = 0; end < s.size(); end++) {
            mp[s[end]]++;
            if(maxFreq < mp[s[end]])
                maxFreq = mp[s[end]];
            while(end - start + 1 - maxFreq > k) {
                mp[s[start]]--;
                start++;
                for(char ch = 'A'; ch <= 'Z'; ch++)
                    maxFreq = max(maxFreq, mp[ch]);
            }
            maxAns = max(maxAns, end - start + 1);
        }
        return maxAns;
    }
};