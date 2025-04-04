#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool solve(string& s, unordered_set<string>& dict, int last, vector<int>& dp) {
        if(last >= s.size())
            return true;
        if(dp[last] != -1)
            return dp[last];
        bool ans = false;
        for(int idx = last; idx < s.size(); idx++) {
            // cout << s.substr(last, idx - last + 1) << endl;
            if(dict.find(s.substr(last, idx - last + 1)) == dict.end()) {}
            else
                ans = ans | solve(s, dict, idx + 1, dp);
        }
        return dp[last] = ans;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<int> dp(s.size(), -1);
        return solve(s, dict, 0, dp);
    }
};
