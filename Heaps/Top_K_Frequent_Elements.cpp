// https://leetcode.com/problems/top-k-frequent-elements/
// Medium

// Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

// Example 1:
// Input: nums = [1,1,1,2,2,3], k = 2
// Output: [1,2]
// Explanation: "1" and "2" are the two most frequent elements.

// Example 2:
// Input: nums = [1], k = 1
// Output: [1]

// Constraints:
// 1 <= nums.length <= 10^5
// -10^4 <= nums[i] <= 10^4
// k is in the range [1, the number of unique elements in the array].
// It is guaranteed that the answer is unique.

// Follow up: Your algorithm's time complexity must be better than O(n log n), where n is the array's size.

#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++)
            mp[nums[i]]++;
        vector<vector<int>> freq(nums.size() + 1);
        for(auto& p : mp) 
            freq[p.second].push_back(p.first);
        // vector<int> ans;
        for(int i = freq.size() - 1; i >= 0 && ans.size() < k; i--) {
            for(int j = 0; j < freq[i].size() && ans.size() < k; j++)
                ans.push_back(freq[i][j]);
        }
        return ans;
    }
};