// https://www.geeksforgeeks.org/problems/palindromic-patitioning4845/1

#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<bool>> palindromes(string& s) {
        vector<vector<bool>> isPalindrome(s.size(), vector<bool>(s.size(), false));
        for(int i = s.size() - 1; i >= 0; i--) {
            for(int j = s.size() - 1; j >= i; j--) {
                if(i == j || i + 1 == j) 
                    isPalindrome[i][j] = (s[i] == s[j]);
                else {
                    if(s[i] != s[j])
                        isPalindrome[i][j] = false;
                    else
                        isPalindrome[i][j] = isPalindrome[i + 1][j - 1];
                }
            }
        }
        return isPalindrome;
    }
    int solve(string& s, int i, vector<int>& dp, vector<vector<bool>>& isPalindrome) {
        if(i == s.size())
            return 0;
        if(dp[i] != -1) 
            return dp[i];
        int ans = INT_MAX;
        for(int idx = i; idx < s.size(); idx++) {
            if(isPalindrome[i][idx])
                ans = min(solve(s, idx + 1, dp, isPalindrome) + 1, ans);
        }
        return dp[i] = ans;
    }
  public:
    int palPartition(string &s) {
        vector<vector<bool>> isPalindrome = palindromes(s);
        vector<int> dp(s.size() + 1, -1);
        return solve(s, 0, dp, isPalindrome) - 1;
    }
};