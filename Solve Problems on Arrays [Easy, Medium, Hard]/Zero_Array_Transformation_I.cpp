// https://leetcode.com/problems/zero-array-transformation-i/
// 3355. Zero Array Transformation I
// Medium

#include<vector>
using namespace std;

class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> prefix(nums.size() + 1, 0);
        for(int i = 0; i < queries.size(); i++) {
            prefix[queries[i][0]]++;
            prefix[queries[i][1] + 1]--;
        }
        int sum = 0;
        for(int i = 0; i < nums.size(); i++) {
            sum += prefix[i];
            if(nums[i] > sum)
                return false;
        }
        return true;
    }
};