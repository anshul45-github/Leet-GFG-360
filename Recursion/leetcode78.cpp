#include<bits/stdc++.h>
using namespace std;

class Solution {
    void subsets_helper(vector<vector<int>>& v, int i, vector<int> nums, vector<int> t) {
        if(i == nums.size()) {
            v.push_back(t);
            return;
        }
        subsets_helper(v, i + 1, nums, t);
        t.push_back(nums[i]);
        subsets_helper(v, i + 1, nums, t);
        return;
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> v;
        vector<int> t;
        subsets_helper(v, 0, nums, t);
        return v;
    }
};
