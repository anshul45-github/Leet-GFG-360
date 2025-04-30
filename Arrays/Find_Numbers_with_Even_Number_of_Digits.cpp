// https://leetcode.com/problems/find-numbers-with-even-number-of-digits/
// 1295. Find Numbers with Even Number of Digits
// Easy

#include<vector>
#include<cmath>
using namespace std;

class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int cnt = 0;
        for(int i = 0; i < nums.size(); i++) {
            int d = (int)(log10(nums[i]));
            if(d & 1)
                cnt++;
        }
        return cnt;
    }
};