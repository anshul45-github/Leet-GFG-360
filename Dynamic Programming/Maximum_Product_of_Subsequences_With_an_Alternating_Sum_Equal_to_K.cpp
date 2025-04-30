// https://leetcode.com/problems/maximum-product-of-subsequences-with-an-alternating-sum-equal-to-k/
// 3509. Maximum Product of Subsequences With an Alternating Sum Equal to K
// Hard

#include<unordered_map>
#include<vector>
using namespace std;

class Solution {
    unordered_map<int, unordered_map<int, unordered_map<int, unordered_map<int, int>>>> memo;
    int solve(vector<int>& nums, int& k, int& limit, int prod, int i, int sum, int isOdd) {
        if(i == nums.size()) {
            if(sum == k && isOdd != 0 && prod <= limit)
                return prod;
            return -1;
        }
        if(memo.count(i) && memo[i].count(sum) && memo[i][sum].count(prod) && memo[i][sum][prod].count(isOdd))
            return memo[i][sum][prod][isOdd];
        int ans = solve(nums, k, limit, prod, i + 1, sum, isOdd);
        if(isOdd == 0)
            ans = max(solve(nums, k, limit, min(prod * nums[i], limit + 1), i + 1, sum + nums[i], 1), ans);
        else if(isOdd == 1)
            ans = max(solve(nums, k, limit, min(prod * nums[i], limit + 1), i + 1, sum - nums[i], 2), ans);
        else
            ans = max(solve(nums, k, limit, min(prod * nums[i], limit + 1), i + 1, sum + nums[i], 1), ans);
        return memo[i][sum][prod][isOdd] = ans;
    }
public:
    int maxProduct(vector<int>& nums, int k, int limit) {
        int sum = 0;
        for(auto &x: nums)
            sum += x;
        if(k > sum || k < -sum)
            return -1;
        memo.clear();
        return solve(nums, k, limit, 1, 0, 0, 0);
    }
};