#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        int n = s.size();
        unordered_map<char, int> mp;
        for(int i = 0; i < n; i++)
            mp[s[i]]++;
        vector<pair<char, int>> vec(mp.begin(), mp.end());
        sort(vec.begin(), vec.end(), [](const pair<char, int>& a, const pair<char, int>& b) {
            return a.second > b.second;
        });
        string str = "";
        for(int i = 0; i < vec.size(); i++) {
            for(int j = 0; j < vec[i].second; j++) {
                str += vec[i].first;
            }
        }
        return str;
    }
};
