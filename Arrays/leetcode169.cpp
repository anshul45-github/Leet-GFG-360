// TC : O(N), SC : O(1)
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 1;
        int candidate = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            if(count == 0)
                candidate = nums[i];
            if(nums[i] == candidate)
                count++;
            else
                count--;
        }
        return candidate;
    }
};
