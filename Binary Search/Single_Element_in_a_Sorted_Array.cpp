// https://leetcode.com/problems/single-element-in-a-sorted-array/

#include<vector>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        while(low <= high) {
            int mid = low + ((high - low) >> 1);
            if(mid + 1 < nums.size() && nums[mid] == nums[mid + 1]) {
                if(mid % 2 == 0)
                    low = mid + 1;
                else
                    high = mid - 1;
            }
            else if(mid - 1 >= 0 && nums[mid] == nums[mid - 1]) {
                if(mid % 2 == 1)
                    low = mid + 1;
                else
                    high = mid - 1;
            }
            else
                return nums[mid];
        }
        return nums[0];
    }
};