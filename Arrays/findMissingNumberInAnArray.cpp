#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int t = 0;
        for(int i = 1; i <= nums.size(); i++)
            t = t ^ i;
        for(int i = 0; i < nums.size(); i++)
            t = t ^ nums[i];
        return t;
    }
};