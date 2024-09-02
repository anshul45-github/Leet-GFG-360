#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxC = 0;
        int currC = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 1)
                currC++;
            else {
                maxC = max(maxC, currC);
                currC = 0;
            }
        }
        maxC = max(maxC, currC);
        return maxC;
    }
};
