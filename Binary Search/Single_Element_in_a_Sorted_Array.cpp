// https://leetcode.com/problems/single-element-in-a-sorted-array/
// Medium

// This code finds the single non-duplicate element in a sorted array where every other element appears exactly twice.

// The function `singleNonDuplicate` takes a vector of integers `nums` as input and returns the single non-duplicate element.

// It uses a binary search approach to efficiently locate the single element.

#include<vector>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        while(l <= r) {
            int mid = l + ((r - l) >> 1);
            if(mid >= 1 && nums[mid - 1] == nums[mid]) {
                if(mid % 2 == 1)
                    l = mid + 1;
                else
                    r = mid - 1;
            }
            else if(mid + 1 < nums.size() && nums[mid + 1] == nums[mid]) {
                if(mid % 2 == 0)
                    l = mid + 1;
                else
                    r = mid - 1;
            }
            else
                return nums[mid];
        }
        return l;
    }
};