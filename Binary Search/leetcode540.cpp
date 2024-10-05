#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        while(l <= r) {
            int mid = l + (r - l) / 2;
            int right, left;
            if(mid > 0 && nums[mid] == nums[mid - 1]) {
                right = r - mid;
                left = mid - l - 1;
                if(right % 2 == 0)
                    r = mid - 2;
                else
                    l = mid + 1;
            }
            else if(mid < nums.size() - 1 && nums[mid] == nums[mid + 1]) {
                right = r - mid - 1;
                left = mid - l;
                if(right % 2 == 0)
                    r = mid - 1;
                else
                    l = mid + 2;
            }
            else
                return nums[mid];
        }
        return nums[0];
    }
};
