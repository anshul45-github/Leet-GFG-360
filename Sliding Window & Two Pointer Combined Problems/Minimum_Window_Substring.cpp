// https://leetcode.com/problems/minimum-window-substring/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> charFreq(128,0);
        for (char c : t) {
            charFreq[c]++;
        }
        int start = -1;
        int begin = 0;
        int count = 0;
        int maxLen = INT_MAX;
        for(int end = 0; end < s.size(); end++) {
            if(charFreq[s[end]] > 0)
                count++;
            charFreq[s[end]]--;
            while(count == t.size()) {
                if(maxLen > end - begin + 1) {
                    start = begin;
                    maxLen = end - start + 1;
                }
                charFreq[s[begin]]++;
                if(charFreq[s[begin]] == 1)
                    count--;
                begin++;
            }
        }
        return maxLen == INT_MAX ? "" : s.substr(start, maxLen);
    }
};
