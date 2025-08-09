// https://leetcode.com/problems/search-insert-position/

#include<vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        while(l <= r) {
            int mid = l + ((r - l) >> 1);
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] < target)
                l++;
            else
                r--;
        }
        return l;
    }
};