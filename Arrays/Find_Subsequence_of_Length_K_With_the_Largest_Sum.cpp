// https://leetcode.com/problems/find-subsequence-of-length-k-with-the-largest-sum/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    static bool cmp(int a, int b) {
        return a > b;
    }
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int> tmp = nums;
        sort(tmp.begin(), tmp.end(), cmp);
        // cout << tmp[0];
        unordered_map<int, int> mp;
        for(int i = 0; i < k; i++)
            mp[tmp[i]]++;
        vector<int> ans;
        for(int x : nums) {
            if(mp[x]) {
                ans.push_back(x);
                mp[x]--;
            }
        }
        return ans;
    }
};