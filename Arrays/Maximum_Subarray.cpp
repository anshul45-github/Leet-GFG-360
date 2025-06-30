// https://leetcode.com/problems/maximum-subarray/

#include<bits/stdc++.h>
using namespace std;

// Naive Approach: Brute Force (TLE)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size(), ans = INT_MIN;
        for(int i = 0; i < n; i++) 
            for(int j = i, curSum = 0; j < n ; j++) 
                curSum += nums[j],
                ans = max(ans, curSum);        
        return ans;
    }
};

// Naive Approach: Recursive Brute Force (TLE)
class Solution {
    int solve(vector<int>& A, int i, bool mustPick) {
        if(i >= A.size()) 
            return mustPick ? 0 : -1e5;       
        if(mustPick)
            return max(0, A[i] + solve(A, i + 1, true));  
        return max(solve(A, i + 1, false), A[i] + solve(A, i + 1, true));
    }
public:
    int maxSubArray(vector<int>& nums) {    
        return solve(nums, 0, false);
    }
};

// Memoization & Tabulation Approach
class Solution {
    int solve(vector<int>& A, int i, bool mustPick, vector<vector<int>>& dp) {
        if(i >= A.size()) 
            return mustPick ? 0 : -1e5;
        if(dp[i][mustPick] != -1)
            return dp[i][mustPick];
        if(mustPick)
            return dp[i][mustPick] = max(0, A[i] + solve(A, i + 1, true, dp));  
        return dp[i][mustPick] = max(solve(A, i + 1, false, dp), A[i] + solve(A, i + 1, true, dp));
    }
    int solveTab(vector<int>& A) {
        vector<vector<int>> dp(A.size() + 1, vector<int>(2, 0));
        dp.back()[0] = -1e5;
        for(int i = A.size() - 1; i >= 0; i--) {
            for(int mustPick = 0; mustPick < 2; mustPick++) {
                if(mustPick)
                    dp[i][mustPick] = max(0, A[i] + dp[i + 1][1]);
                else
                    dp[i][mustPick] = max(dp[i + 1][0], A[i] + dp[i + 1][1]);
            }
        }
        return dp[0][0];
    }
public:
    int maxSubArray(vector<int>& nums) {   
        // vector<vector<int>> dp(nums.size() + 1, vector<int>(2, -1)); 
        // return solve(nums, 0, false, dp);

        return solveTab(nums);
    }
};

// 1D Dynamic Programming Approach
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        for(int i = 1; i < nums.size(); i++) 
            dp[i] = max(nums[i], nums[i] + dp[i-1]);        
        return *max_element(begin(dp), end(dp));
    }
};

// Kadane's Algorithm
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currSum = 0;
        int maxSum = INT_MIN;
        for(int x : nums) {
            currSum += x;
            if(x > currSum)
                currSum = x;
            maxSum = max(currSum, maxSum);
        }
        return maxSum;
    }
};

// Divide and Conquer Approach
class Solution {
    int maxSubArray(vector<int>& A, int L, int R){
        if(L > R) 
            return INT_MIN;
        int mid = L + ((R - L) >> 1);
        int leftSum = 0, rightSum = 0;
        for(int i = mid - 1, curSum = 0; i >= L; i--)
            curSum += A[i],
            leftSum = max(leftSum, curSum);
        for(int i = mid + 1, curSum = 0; i <= R; i++)
            curSum += A[i],
            rightSum = max(rightSum, curSum);        
        return max({maxSubArray(A, L, mid - 1), maxSubArray(A, mid + 1, R), leftSum + A[mid] + rightSum});
    }	
public:
    int maxSubArray(vector<int>& nums) {
        return maxSubArray(nums, 0, nums.size() - 1);
    }
};

// Optimized Divide and Conquer Approach
class Solution {
    vector<int> pre, suf;
public:
    int maxSubArray(vector<int>& A, int L, int R) {
        if(L == R) 
            return A[L];
        int mid = L + ((R - L) >> 1);
        return max({maxSubArray(A, L, mid), maxSubArray(A, mid + 1, R), pre[mid] + suf[mid + 1]});
    }	
    int maxSubArray(vector<int>& nums) {
        pre = nums;
        suf = nums;
        for(int i = 1; i < nums.size(); i++)  
            pre[i] += max(0, pre[i - 1]);
        for(int i = nums.size() - 2; i >= 0; i--)   
            suf[i] += max(0, suf[i + 1]);
        return maxSubArray(nums, 0, nums.size() - 1);
    }
};