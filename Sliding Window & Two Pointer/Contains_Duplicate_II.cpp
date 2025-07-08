// https://leetcode.com/problems/contains-duplicate-ii/

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
            if(i > k)
                mp[nums[i - k - 1]]--;
            if(mp[nums[i]] > 1)
                return true;
        }
        return false;
    }
};