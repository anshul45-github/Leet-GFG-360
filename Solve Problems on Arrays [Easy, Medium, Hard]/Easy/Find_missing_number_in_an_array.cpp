// https://leetcode.com/problems/missing-number/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int Xor = 0;
        for(int i = 0; i < nums.size(); i++)
            Xor = Xor ^ nums[i];
        for(int i = 0; i <= nums.size(); i++)
            Xor = Xor ^ i;
        return Xor;
    }
};