// https://www.geeksforgeeks.org/problems/subset-sums2234/1

#include<bits/stdc++.h>
using namespace std;

class Solution {
    void subsets_helper(vector<int>& v, int i, vector<int>& nums, int sum) {
        if(i == nums.size()) {
            v.push_back(sum);
            return;
        }
        subsets_helper(v, i + 1, nums, sum + nums[i]);
        subsets_helper(v, i + 1, nums, sum);
        return;
    }
  public:
    vector<int> subsetSums(vector<int>& arr) {
        vector<int> sums;
        subsets_helper(sums, 0, arr, 0);
        return sums;
    }
};
