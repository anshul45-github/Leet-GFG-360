// https://leetcode.com/problems/palindrome-partitioning-ii/

#include<bits/stdc++.h>
using namespace std;

// Optimized Approach -> TC - O(n^2)
class Solution {
    vector<vector<bool>> getPalindromes(string& s) {
        vector<vector<bool>> palindromes(s.size(), vector<bool>(s.size(), false));
        for(int i = s.size() - 1; i >= 0; i--) {
            for(int j = i; j < s.size(); j++) {
                if(i + 1 <= j - 1)
                    palindromes[i][j] = (s[i] == s[j] && palindromes[i + 1][j - 1]);
                else
                    palindromes[i][j] = (s[i] == s[j]);
            }
        }
        return palindromes;
    }
    int solve(string& s, vector<vector<bool>>& palindromes, int i, vector<int>& dp) {
        if(palindromes[i].back())
            return 0;
        if(dp[i] != -1)
            return dp[i];
        int ans = INT_MAX;
        for(int idx = i; idx < s.size(); idx++) {
            if(palindromes[i][idx])
                ans = min(ans, solve(s, palindromes, idx + 1, dp) + 1);
        }
        return dp[i] = ans;
    }
public:
    int minCut(string s) {
        vector<vector<bool>> palindromes = getPalindromes(s);
        vector<int> dp(s.size(), -1);
        return solve(s, palindromes, 0, dp);
    }
};

// TC - O(n^3)
class Solution {
    bool isPalindrome(string& s, int i, int j) {
        while(i < j) {
            if(s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    int solve(string& s, int i, int j, vector<int>& dp) {
        if(isPalindrome(s, i, j))
            return 0;
        if(dp[i] != -1)
            return dp[i];
        int ans = INT_MAX;
        for(int k = i; k < j; k++) {
            if(isPalindrome(s, i, k)) {
                int temp = solve(s, k + 1, j, dp) + 1;
                ans = min(ans, temp);
            }
        }
        return dp[i] = ans;
    }
public:
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n + 1, -1);
        return solve(s, 0, n - 1, dp);
    }
};