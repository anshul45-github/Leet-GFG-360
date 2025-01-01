#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0, currEnd = 0, reach = 0;
        for(int i = 0; i < nums.size() - 1; i++) {
            reach = max(reach, i + nums[i]);
            if(i == currEnd) {
                jumps++;
                currEnd = reach;
            }
        }
        return jumps;
    }
};
