// https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/

#include<bits/stdc++.h>
using namespace std;    

#define N 1000000007

class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int i = 0, j = nums.size() - 1;
        long long ans = 0;
        vector<int> power(nums.size());
        power[0] = 1;
        for(int i = 1; i < nums.size(); ++i) 
            power[i] = (power[i - 1] * 2) % N;
        while(i <= j) {
            while(i <= j && nums[i] + nums[j] > target)
                j--;
            if(i <= j)  {
                ans += power[j - i];
                ans %= N;
            }
            i++;
        }
        return ans;
    }
};