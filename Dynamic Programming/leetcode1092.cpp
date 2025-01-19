#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string shortestCommonSupersequence(string a, string b) {
        vector<vector<int>> dp(a.size() + 1, vector<int>(b.size() + 1, 0));
        for(int i = 1; i <= a.size(); i++) {
            for(int j = 1; j <= b.size(); j++) {
                if(a[i - 1] == b[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        string ans = "";
        int i = a.size(), j = b.size();
        while(i > 0 && j > 0) {
            if(a[i - 1] == b[j - 1]) {
                ans = a[i - 1] + ans;
                i--;
                j--;
            }
            else {
                // first = a[i - 1] + first;
                // second = b[j - 1] + first;
                if(dp[i][j - 1] > dp[i - 1][j]) {
                    ans = b[j - 1] + ans;
                    j--;
                }
                else {
                    ans = a[i - 1] + ans;
                    i--;
                }
            }
        }
        ans = a.substr(0, i) + ans;
        ans = b.substr(0, j) + ans;
        return ans;
    }
};
