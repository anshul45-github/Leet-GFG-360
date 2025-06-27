// https://www.geeksforgeeks.org/problems/longest-common-substring1452/1

#include<bits/stdc++.h>
using namespace std;

class Solution { 
    int solveTab(string& s1, string& s2) {
        vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, 0));
        int maxi = 0;
        for(int i = 1; i <= s1.size(); i++) {
            for(int j = 1; j <= s2.size(); j++) {
                if(s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                    maxi = max(maxi, dp[i][j]);
                }
            }
        }
        return maxi;
    }
  public:
    int longestCommonSubstr(string& s1, string& s2) {
        return solveTab(s1, s2);
    }
};