// https://leetcode.com/problems/partition-array-into-two-equal-product-subsets/
// Medium

#include <vector>
using namespace std;

typedef __int128 ll;

class Solution {
    bool solve(vector<int>& nums, long long target, int i, ll prod) {
        if(prod > target)
            return false;
        if(prod == target)
            return true;
        if(i == nums.size())
            return false;
        if(solve(nums, target, i + 1, prod * nums[i]))
            return true;
        if(solve(nums, target, i + 1, prod))
            return true;
        return false;
    }
public:
    bool checkEqualPartitions(vector<int>& nums, long long target) {
        ll prod = 1;
        for(int x : nums) {
            prod *= x;
            if(prod > (ll)target * target)
                return false;
        }
        if(prod != (ll)target * target)
            return false;
        return solve(nums, target, 0, 1);
    }
};