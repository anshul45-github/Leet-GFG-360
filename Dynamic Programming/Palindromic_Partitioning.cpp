// https://www.geeksforgeeks.org/problems/palindromic-patitioning4845/1
// Hard

// Given a string s, the task is to find the minimum number of cuts needed to partition the string such that every substring is a palindrome.

// A palindrome is a string that reads the same backward as forward.

// The problem can be solved using dynamic programming.

#include<string>
#include<vector>
#include<climits>
using namespace std;

class Solution {
    bool isPalind(int i, int j, string& s) {
        while(i < j) {
            if(s[i] != s[j]) 
                return false;
            i++;
            j--;
        }
        return true;
    }
    int helper(int i, int j, string& s, vector<vector<int>>& dp) {
        if(i >= j) 
            return 0;
        if(dp[i][j] != -1) 
            return dp[i][j];
        int mini = INT_MAX;
        for(int k = i; k <= j; k++){
            if(isPalind(i, k, s)) {
                dp[i][k] = 0;
                int temp = helper(k + 1, j, s, dp);
                if(k != j)
                    temp++;
                mini = min(mini, temp);
            }
        }
        return dp[i][j] = mini;
    }
  public:
    int palPartition(string &s) {
        vector<vector<int>> dp(s.size() + 1, vector<int>(s.size() + 1, -1));
        return helper(0, s.size() - 1, s, dp);
    }
};