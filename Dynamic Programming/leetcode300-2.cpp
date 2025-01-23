// TC : O(nlogn)
#include<bits/stdc++.h>
using namespace std;

class Solution {
    int findCeil(vector<int>& res, int num) {
        int l = 0;
        int h = res.size() - 1;
        while(l <= h) {
            int mid = l + ((h - l) >> 1);
            if(res[mid] > num)
                h--;
            else if(res[mid] == num)
                return mid;
            else
                l++;
        }
        return h + 1;
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> res;
        for(int i = 0; i < nums.size(); i++) {
            if(res.empty() || res[res.size() - 1] < nums[i])
                res.push_back(nums[i]);
            else if(res[res.size() - 1] > nums[i]) {
                int idx = findCeil(res, nums[i]);
                res[idx] = nums[i];
            }
        }
        return res.size();
    }
};
