// https://leetcode.com/problems/word-break/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool canBrk(int start, string& s, unordered_set<string>& wordDict) {
        int n = s.size();
        if(start == n) return 1;
        string sub;
        for(int i = start; i < n; i++) {
            if(wordDict.count(sub += s[i]) && canBrk(i + 1, s, wordDict)) 
                return 1;
        }
        return 0;
    }

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // Put all words into an unordered_set
        unordered_set<string> set(wordDict.begin(), wordDict.end());
        return canBrk(0, s, set);
    }
};
