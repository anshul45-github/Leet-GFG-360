#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool isPossible(vector<int> a, int t, int d, int n) {
        int sum = 0;
        for(int i = 0; i < n; i++) {
            sum += a[i] % d == 0 ? a[i] / d : (a[i] / d) + 1;
        }
        return sum <= t;
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int l = 1;
        int h = INT_MIN;
        for(int i = 0; i < n; i++) {
            // l = min(l, nums[i]);
            h = max(h, nums[i]);
        }
        int div = h;
        while(l <= h) {
            int mid = l + ((h - l) >> 1);
            if(isPossible(nums, threshold, mid, n)) {
                div = mid;
                h = mid - 1;
            }
            else
                l = mid + 1;
        }
        return div;
    }
};
