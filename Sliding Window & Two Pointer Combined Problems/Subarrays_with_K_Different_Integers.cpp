// https://leetcode.com/problems/subarrays-with-k-different-integers/
// 992. Subarrays with K Different Integers
// Hard

#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
    int atMost(vector<int>& nums, int k) {
        if(k == 0)
            return 0;
        int ans = 0;
        int start = 0;
        unordered_map<int, int> mp;
        for(int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
            while(mp.size() > k) {
                mp[nums[start]]--;
                if(!mp[nums[start]]) {
                    mp.erase(nums[start]);
                }
                start++;
            }
            ans += i - start + 1;
        }
        return ans;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }
};
