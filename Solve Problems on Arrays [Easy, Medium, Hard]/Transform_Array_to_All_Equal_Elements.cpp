// https://leetcode.com/problems/transform-array-to-all-equal-elements/
// Medium

// TC : O(N), SC : O(1)

#include <vector>
using namespace std;

class Solution {
public:
    bool canMakeEqual(vector<int>& nums, int k) {
        int lastOne = -1;
        int lastMinus = -1;
        int oneOps = 0;
        int minusOps = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 1) {
                if(lastOne == -1)
                    lastOne = i;
                else {
                    oneOps += i - lastOne;
                    lastOne = -1;
                }
            }
            else {
                if(lastMinus == -1)
                    lastMinus = i;
                else {
                    minusOps += i - lastMinus;
                    lastMinus = -1;
                }
            }
        }
        bool one = (lastOne == -1 && oneOps <= k);
        bool minus = (lastMinus == -1 && minusOps <= k);
        return one || minus;
    }
};