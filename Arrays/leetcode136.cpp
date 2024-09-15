// TC : O(N), SC : O(1)
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int x = 0;
        for(int i = 0; i < nums.size(); i++)
            x = x ^ nums[i];
        return x;
    }
};
