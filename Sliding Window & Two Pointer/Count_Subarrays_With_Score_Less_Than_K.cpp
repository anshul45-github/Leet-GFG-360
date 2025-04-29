// https://leetcode.com/problems/count-subarrays-with-score-less-than-k/
// 2302. Count Subarrays With Score Less Than K
// Hard

#include<vector>
using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long sum = 0;
        int l = 0;
        long long cnt = 0;
        for(int r = 0; r < nums.size(); r++) {
            sum += nums[r];
            while(sum * (r - l + 1) >= k) {
                sum -= nums[l];
                l++;
            }
            if(sum * (r - l + 1) < k) {
                cnt += r - l + 1;
                // cout << l << " " << r << endl;
            }
        }
        return cnt;
    }
};