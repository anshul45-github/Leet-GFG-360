#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = 0;
        int n = nums.size();
        int r = n - 1;
        int idx = -1;
        while(l <= r) {
            int mid = l + (r - l) / 2;
            if(nums[mid] == target) {
                idx = mid;
                break;
            }
            else if(nums[mid] < target)
                l = mid + 1;
            else
                r = mid - 1;
        }
        if(idx == -1) {
            vector<int> v = {-1, -1};
            return v;
        }
        int mi = idx;
        int ma = idx;
        for(int i = idx - 1; i >= 0 && nums[i] == nums[idx]; i--)
            mi--;
        for(int i = idx + 1; i < n && nums[i] == nums[idx]; i++)
            ma++;
        vector<int> v = {mi, ma};
        return v;
    }
};
