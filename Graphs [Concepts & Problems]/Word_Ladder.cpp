#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<string> q;
        int lvl = 1;
        int maxVal = INT_MAX;
        q.push(beginWord);
        q.push("");
        unordered_map<string, bool> mp;
        for(string str : wordList)
            mp[str] = true;
        while(!q.empty()) {
            string curr = q.front();
            q.pop();
            if(curr == "") {
                if(q.empty())
                    break;
                lvl++;
                q.push("");
            }
            if(curr == endWord) {
                maxVal = min(maxVal, lvl);
                continue;
            }
            for(int i = 0; i < curr.size(); i++) {
                char ch = curr[i];
                for(char c = 'a'; c <= 'z'; c++) {
                    if(c == ch)
                        continue;
                    curr[i] = c;
                    if(mp[curr]) {
                        q.push(curr);
                        mp[curr] = false;
                    }
                }
                curr[i] = ch;
            }
        }
        return maxVal == INT_MAX ? 0 : maxVal;
    }
};
