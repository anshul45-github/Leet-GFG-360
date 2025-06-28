// https://leetcode.com/problems/largest-divisible-subset/

#include<bits/stdc++.h>
using namespace std;

// Same as Longest Increasing Subsequence, but with a condition that the current element must be divisible by the previous element and we must sort the array first.

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        vector<int> dp(arr.size(), 1);
        vector<int> hash(arr.size());
        for(int i = 0; i < arr.size(); i++)
            hash[i] = i;
        int lenlis = 1;
        int lislast = 0;
        for(int i = 0; i < arr.size(); i++) {
            for(int j = 0; j < i; j++) {
                if(arr[i] % arr[j] == 0 && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    hash[i] = j;
                }
            }
            if(dp[i] > lenlis) {
                lenlis = dp[i];
                lislast = i;
            }
        }
        vector<int> lis;
        while(hash[lislast] != lislast) {
            lis.push_back(arr[lislast]);
            lislast = hash[lislast];
        }
        lis.push_back(arr[lislast]);
        reverse(lis.begin(), lis.end());
        return lis;
    }
};