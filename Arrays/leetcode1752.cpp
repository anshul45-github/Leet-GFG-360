#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(vector<int>& nums) {
        bool bug = false;
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] < nums[i - 1]) {
                if(bug)
                    return false;
                bug = true;
            }
        }
        if(bug) {
            if(nums[nums.size() - 1] > nums[0])
                return false;
        }
        return true;
    }
};
