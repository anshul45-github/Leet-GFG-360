// https://leetcode.com/problems/count-complete-subarrays-in-an-array/
// 2799. Count Complete Subarrays in an Array
// Medium

#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;

class Solution {
    int distinctLessThanEqualTo(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int i = 0;
        int j = 0;
        int dist = 0;
        int cnt = 0;
        while(j < nums.size()) {
            if(!mp[nums[j]])
                dist++;
            mp[nums[j]]++;
            while(dist > k) {
                mp[nums[i]]--;
                if(!mp[nums[i]])
                    dist--;
                i++;
            }
            cnt += j - i + 1;
            j++;
        }
        return cnt;
    }
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int> s;
        for(int j : nums)
            s.insert(j);
        int distinct = s.size();
        return distinctLessThanEqualTo(nums, distinct) - distinctLessThanEqualTo(nums, distinct - 1);
    }
};