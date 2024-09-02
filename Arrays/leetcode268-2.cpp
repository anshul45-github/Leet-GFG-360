// TC : O(N), SC : O(1)

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int expectedSum = n * (n + 1) / 2;
        int currSum = 0;
        for(int i = 0; i < nums.size(); i++)
            currSum += nums[i];
        return expectedSum - currSum;
    }
};
