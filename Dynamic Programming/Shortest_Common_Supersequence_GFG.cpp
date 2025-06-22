// https://www.geeksforgeeks.org/problems/shortest-common-supersequence0322/1
// Medium

#include<vector>
#include<string>
using namespace std;

class Solution {
    int solveMem(string& s1, string& s2, int i, int j, vector<vector<int>>& dp) {
        if(i == s1.size())
            return s2.size() - j;
        if(j == s2.size())
            return s1.size() - i;
        if(dp[i][j] != -1)
            return dp[i][j];
        if(s1[i] == s2[j])
            return dp[i][j] = solveMem(s1, s2, i + 1, j + 1, dp) + 1;
        return dp[i][j] = min(solveMem(s1, s2, i + 1, j, dp), solveMem(s1, s2, i, j + 1, dp)) + 1;
    }
    int solveTab(string& s1, string& s2) {
        vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1));
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
        return dp[0][0];
    }
    int spaceOptimization(string& s1, string& s2) {
        vector<int> next(s2.size() + 1);
        for(int i = 0; i <= s2.size(); i++)
            next[i] = s2.size() - i;
        for(int i = s1.size() - 1; i >= 0; i--) {
            vector<int> curr(s2.size() + 1);
            curr[s2.size()] = s1.size() - i;
            for(int j = s2.size() - 1; j >= 0; j--) {
                if(s1[i] == s2[j])
                    curr[j] = next[j + 1] + 1;
                else
                    curr[j] = min(next[j], curr[j + 1]) + 1;
            }
            next = curr;
        }
        return next[0];
    }
  public:
    int shortestCommonSupersequence(string &s1, string &s2) {
        // vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, -1));
        // return solve(s1, s2, 0, 0, dp);
        
        // return solveTab(s1, s2);
        
        return spaceOptimization(s1, s2);
    }
};