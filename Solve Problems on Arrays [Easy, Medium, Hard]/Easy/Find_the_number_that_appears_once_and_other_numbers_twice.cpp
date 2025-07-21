// https://leetcode.com/problems/single-number/

#include<vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int y = 0;
        for(int x : nums)
            y = y ^ x;
        return y;
    }
};