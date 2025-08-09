// https://leetcode.com/problems/binary-search/

#include<vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        while(l <= r) {
            int mid = l + ((r - l) >> 1);
            if(nums[mid] == target)
                return mid;
            if(nums[mid] > target)
                r--;
            else
                l++;
        }
        return -1;
    }
};