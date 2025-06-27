// https://leetcode.com/problems/shortest-common-supersequence/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    void solveTab(string& s1, string& s2, vector<vector<int>>& dp) {
        // vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1));
        for(int i = 0; i <= s1.size(); i++)
            dp[i][s2.size()] = s1.size() - i;
        for(int i = 0; i <= s2.size(); i++)
            dp[s1.size()][i] = s2.size() - i;
        for(int i = s1.size() - 1; i >= 0; i--) {
            for(int j = s2.size() - 1; j >= 0; j--) {
                if(s1[i] == s2[j])
                    dp[i][j] = dp[i + 1][j + 1] + 1;
                else
                    dp[i][j] = min(dp[i + 1][j], dp[i][j + 1]) + 1;
            }
        }
        return;
        
    }
public:
    string shortestCommonSupersequence(string& s1, string& s2) {
        vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1));
        solveTab(s1, s2, dp);
        // for(int i = 0; i < dp.size(); i++) {
        //     for(int j = 0; j < dp[i].size(); j++)
        //         cout << dp[i][j] << " ";
        //     cout << endl;
        // }
        int i = 0, j = 0;
        string curr = "";
        while(i < s1.size() && j < s2.size()) {
            if(s1[i] == s2[j]) {
                curr += s1[i];
                i++;
                j++;
            }
            else if(i + 1 <= s1.size() && dp[i + 1][j] < dp[i][j + 1]) {
                curr += s1[i];
                i++;
            }
            else {
                curr += s2[j];
                j++;
            }
        }
        while(i < s1.size()) {
            curr += s1[i];
            i++;
        }
        while(j < s2.size()) {
            curr += s2[j];
            j++;
        }
        return curr;
    }
};