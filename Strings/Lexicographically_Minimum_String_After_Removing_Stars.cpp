// https://leetcode.com/problems/lexicographically-minimum-string-after-removing-stars/
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
    int findMin(unordered_map<char, vector<int>>& mp) {
        for(char ch = 'a'; ch <= 'z'; ch++) {
            if(mp[ch].size()) {
                int ans = mp[ch].back();
                mp[ch].pop_back();
                return ans;
            }
        }
        return -1;
    }
public:
    string clearStars(string s) {
        unordered_map<char, vector<int>> mp;
        vector<bool> present(s.size(), true);
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '*') {
                int mini = findMin(mp);
                present[mini] = false;
                present[i] = false;
            }
            else
                mp[s[i]].push_back(i);
        }
        string t = "";
        for(int i = 0; i < s.size(); i++) {
            if(present[i])
                t += s[i];
        }
        return t;
    }
};