// https://leetcode.com/problems/top-k-frequent-elements/

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