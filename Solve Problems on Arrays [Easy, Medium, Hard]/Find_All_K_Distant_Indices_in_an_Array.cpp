// https://leetcode.com/problems/find-all-k-distant-indices-in-an-array/
// Easy

// This code finds all indices in an array that are at most k distance away from any index containing a specific key value.
// Time complexity: O(n)
// Space complexity: O(n)

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<pair<int, int>> pairs;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == key) {
                pairs.push_back({max(0, i - k), min(i + k, (int)nums.size() - 1)});
            }
        }
        vector<int> v;
        for(auto& p : pairs) {
            int start;
            if(v.size() == 0)
                start = p.first;
            else
                start = max(p.first, v.back() + 1);
            for(int i = start; i <= p.second; i++)
                v.push_back(i);
        }
        return v;
    }
};