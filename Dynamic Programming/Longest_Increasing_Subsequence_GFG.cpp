// https://www.geeksforgeeks.org/problems/longest-increasing-subsequence-1587115620/1

#include<bits/stdc++.h>
using namespace std;

// 1D DP Approach

// Check Longest_Increasing_Subsequence.cpp for more approaches

class Solution {
  public:
    int lis(vector<int>& arr) {
        vector<int> dp(arr.size(), 1);
        int lenlis = 1;
        for(int i = 0; i < arr.size(); i++) {
            for(int j = 0; j < i; j++) {
                if(arr[i] > arr[j] && dp[j] + 1 > dp[i]) 
                    dp[i] = dp[j] + 1;
            }
            if(dp[i] > lenlis) 
                lenlis = dp[i];
        }
        return lenlis;
    }
};