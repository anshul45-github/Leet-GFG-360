#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSum(vector<int>& a, int l, int r) {
        if(l > r)
            return INT_MIN;
        int mid = l + (r - l) / 2;
        int leftSum = 0;
        int rightSum = 0;
        for(int i = mid - 1, currSum = 0; i >= l; i--) {
            currSum += a[i];
            leftSum = max(leftSum, currSum);
        }
        for(int i = mid + 1, currSum = 0; i <= r; i++) {
            currSum += a[i];
            rightSum = max(rightSum, currSum);
        }
        return max(max(maxSum(a, l, mid - 1), maxSum(a, mid + 1, r)), leftSum + rightSum + a[mid]);
    }
    int maxSubArray(vector<int>& nums) {
        return maxSum(nums, 0, nums.size() - 1);
    }
};
