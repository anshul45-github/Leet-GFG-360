// https://leetcode.com/problems/median-of-two-sorted-arrays/description/
// 4. Median of Two Sorted Arrays
// Hard

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1);
        int l = 0;
        int r = nums1.size();
        int idx = (nums1.size() + nums2.size()) >> 1;
        while(l <= r) {
            int mid1 = l + ((r - l) >> 1);
            int mid2 = idx - mid1;
            int l1 = INT_MIN;
            int l2 = INT_MIN;
            int r1 = INT_MAX;
            int r2 = INT_MAX;
            if(mid1 - 1 >= 0)
                l1 = nums1[mid1 - 1];
            if(mid2 - 1 >= 0)
                l2 = nums2[mid2 - 1];
            if(mid1 < nums1.size())
                r1 = nums1[mid1];
            if(mid2 < nums2.size())
                r2 = nums2[mid2];
            if(l1 <= r2 && l2 <= r1) {
                // cout << l1 << " " << l2 << " " << r1 << " " << r2;
                if((nums1.size() + nums2.size()) % 2)
                    return min(r1, r2);
                else
                    return ((double)(max(l1, l2) + (double)min(r1, r2)) / 2);
            }
            else if(l1 <= r2)
                l = mid1 + 1;
            else
                r = mid1 - 1;
        }
        return 0;
    }
};