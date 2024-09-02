// TC : O(N), SC : O(N)

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        bool* present = new bool[nums.size() + 1];
        for(int i = 0; i <= nums.size(); i++)
            present[i] = false;
        for(int i = 0; i < nums.size(); i++)
            present[nums[i]] = true;
        for(int i = 0; i <= nums.size(); i++) {
            if(!present[i])
                return i;
        }
        return -1;
    }
};
