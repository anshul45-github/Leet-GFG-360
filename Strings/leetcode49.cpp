#include<bits/stdc++.h>
using namespace std;

int N = 1e9 + 7;

class Solution {
    long long hashStr(string& str) {
        long long p = 1LL;
        long long hash = 0;
        for(int i = 0; i < str.size(); i++) {
            hash += p * (str[i] - 'a' + 1);
            hash %= N;
            p *= 31;
            p %= N;
        }
        return hash;
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<int, vector<string>> mp;
        vector<vector<string>> v;
        for(int i = 0; i < strs.size(); i++) {
            string t = strs[i];
            sort(t.begin(), t.end());
            int h = hashStr(t);
            mp[h].push_back(strs[i]);
        }
        for(auto p : mp) {
            v.push_back(p.second);
        }
        return v;
    }
};