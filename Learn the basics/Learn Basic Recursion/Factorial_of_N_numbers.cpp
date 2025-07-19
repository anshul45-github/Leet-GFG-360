// https://www.geeksforgeeks.org/problems/find-all-factorial-numbers-less-than-or-equal-to-n3548/1

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void helper(long long n, int i, long long k, vector<long long>& nums) {
        if(k > n)
            return;
        nums.push_back(k);
        helper(n, i + 1, k * i, nums);
        return;
    }
  
    vector<long long> factorialNumbers(long long n) {
        int i = 2;
        long long k = 1;
        vector<long long> nums;
        helper(n, i, k, nums);
        return nums;
    }
};
