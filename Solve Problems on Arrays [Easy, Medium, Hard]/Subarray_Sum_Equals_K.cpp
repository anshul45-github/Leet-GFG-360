// https://leetcode.com/problems/subarray-sum-equals-k/ 

#include<bits/stdc++.h>
using namespace std;

// Brute Force Approach (TLE)
class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
        int n = arr.size(); 
        int ans = 0; 
        for(int i = 0; i < n; i++) {
            int sum = arr[i];
            if(sum == k)
                ans++;
            for(int j = i + 1; j < n; j++) {
                sum += arr[j];
                if(sum == k)
                    ans++;
            }
        }
        return ans; 
    }
};

// Optimal Approach: Using Prefix Sum
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;
        int currSum = 0;
        int ans = 0;
        for(int x : nums) {
            currSum += x;
            ans += mp[currSum - k];
            mp[currSum]++;
        }
        return ans;
    }
};