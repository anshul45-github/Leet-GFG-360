// https://www.geeksforgeeks.org/problems/maximum-sum-increasing-subsequence4749/1
// Medium

// Given an array of integers, find the maximum sum of an increasing subsequence of the array.

// An increasing subsequence is a subsequence where each element is greater than the previous one.

// The maximum sum is the sum of the elements in the subsequence.

// The problem can be solved using dynamic programming.

// The time complexity is O(n^2) and the space complexity is O(n).

// The solution uses a tabulation approach to build the solution iteratively.

#include <bits/stdc++.h>
using namespace std;

class Solution {
    int solveTab(vector<int>& arr) {
        vector<int> next(arr.size() + 1, 0);
        for(int i = arr.size() - 1; i >= 0; i--) {
            vector<int> curr(arr.size() + 1, 0);
            for(int j = i - 1; j >= -1; j--) {
                curr[j + 1] = next[j + 1];
                if(j == -1 || arr[j] < arr[i])
                    curr[j + 1] = max(curr[j + 1], next[i + 1] + arr[i]);
            }
            next = curr;
        }
        return next[0];
    }
  public:
    int maxSumIS(vector<int>& arr) {
        return solveTab(arr);
    }
};