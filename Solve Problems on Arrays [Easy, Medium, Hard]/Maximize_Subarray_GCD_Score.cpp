// https://leetcode.com/problems/maximize-subarray-gcd-score/
// Hard

// Given an integer array nums and an integer k, return the maximum score of a subarray of nums.

#include <vector>
using namespace std;

class Solution {
    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
public:
    long long maxGCDScore(vector<int>& nums, int k) {
        vector<int> twos(nums.size(), 0);
        for(int i = 0; i < nums.size(); i++) {
            int x = nums[i];
            while(x % 2 == 0) {
                twos[i]++;
                x = x / 2;
            }
        }
        long long maxScore = 0;
        int GCD = 0;
        for(int i = 0; i < nums.size(); i++) {
            vector<int> nos(30, 0);
            int GCD = 0;
            for(int j = i; j < nums.size(); j++) {
                GCD = gcd(nums[j], GCD);
                long long score = 1LL * GCD * (j - i + 1);
                nos[twos[j]]++;
                for(int l = 0; l < 30; l++) {
                    if(nos[l] > 0) {
                        if(nos[l] <= k)
                            score *= 2LL;
                        break;
                    }
                }
                maxScore = max(score, maxScore);
            }
        }
        return maxScore;
    }
};