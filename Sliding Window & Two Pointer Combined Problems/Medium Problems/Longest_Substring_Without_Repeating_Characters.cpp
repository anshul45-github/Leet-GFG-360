// https://leetcode.com/problems/longest-substring-without-repeating-characters/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0)
            return 0;
        unordered_map<char, bool> mp;
        int start = 0;
        int end = 0;
        int maxLen = 1;
        mp[s[0]] = true;
        for(int i = 1; i < s.size(); i++) {
            end++;
            if(mp[s[i]]) {
                maxLen = max(maxLen, end - start);
                cout << i << " " << maxLen << endl;
                while(s[start] != s[i]) {
                    mp[s[start]] = false;
                    start++;
                }
                start++;
            }
            else {
                mp[s[end]] = true;
            }
        }
        cout << start << endl;
        maxLen = max(end - start + 1, maxLen);
        return maxLen;
    }
};
