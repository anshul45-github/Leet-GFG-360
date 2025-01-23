#include<bits/stdc++.h>
using namespace std;

class Solution {
    static bool cmp(string a, string b) {
        return a.size() < b.size();
    }
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), cmp);
        int maxi = 1;
        unordered_map<string, int> dp;
        for(int i = 0; i < words.size(); i++) {
            string curr = words[i];
            dp[curr] = 1;
            for(int k = 0; k < curr.size(); k++) {
                string pred = curr.substr(0, k) + curr.substr(k + 1);
                if(dp.count(pred))
                    dp[curr] = max(dp[curr], dp[pred] + 1);
            }
            maxi = max(maxi, dp[curr]);
        }
        return maxi;
    }
};
