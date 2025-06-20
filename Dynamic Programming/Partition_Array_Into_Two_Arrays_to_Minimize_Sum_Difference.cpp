// https://leetcode.com/problems/partition-array-into-two-arrays-to-minimize-sum-difference/
// Hard

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int x : nums)
            sum += x;
        int N = n >> 1;
        vector<vector<int>> left(N + 1);
        vector<vector<int>> right(N + 1);
        for(int mask = 0; mask < (1 << N); mask++) {
            int sz = 0, l = 0, r = 0;
            for(int i = 0; i < N; i++) {
                if(mask & (1 << i)) {
                    sz++;
                    l += nums[i];
                    r += nums[i + N];
                }
            }
            left[sz].push_back(l);
            right[sz].push_back(r);
        }
        for(int i = 0; i <= N; i++)
            sort(right[i].begin(), right[i].end());
        int res = min(abs(sum - 2 * left[N][0]), abs(sum - 2 * right[N][0]));
        for(int i = 1; i <= N; i++) {
            for(auto& a : left[i]) {
                int b = (sum - (a << 1)) >> 1;
                int rsz = N - i;
                auto& v = right[rsz];
                auto itr = lower_bound(v.begin(), v.end(), b);
                if(itr != v.end())
                    res = min(res, abs(sum - 2 * (a + *itr)));
                if(itr != v.begin()) {
                    auto it = itr;
                    it--;
                    res = min(res, abs(sum - 2 * (a + *it)));
                }
            }
        }
        return res;
    }
};