// https://leetcode.com/problems/word-ladder/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> s(wordList.begin(), wordList.end());
        if(s.count(beginWord))
            s.erase(beginWord);
        queue<string> q;
        q.push(beginWord);
        int lvl = 0;
        while(!q.empty()) {
            int sz = q.size();
            for(int i = 0; i < sz; i++) {
                string curr = q.front();
                q.pop();
                // cout << curr << " ";
                if(curr == endWord)
                    return lvl + 1;
                for(int j = 0; j < curr.size(); j++) {
                    char ch = curr[j];
                    for(char c = 'a'; c <= 'z'; c++) {
                        curr[j] = c;
                        if(s.count(curr)) {
                            q.push(curr);
                            s.erase(curr);
                        }
                    }
                    curr[j] = ch;
                }
            }
            lvl++;
        }
        return 0;
    }
};