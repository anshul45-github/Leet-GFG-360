// https://leetcode.com/problems/median-of-two-sorted-arrays/

#include<bits/stdc++.h>
using namespace std;

// Approach 1 - Brute Force (Merging and Sorting)
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        vector<int> merged;
        for(int i = 0; i < n; i++) 
            merged.push_back(nums1[i]);
        for(int i = 0; i < m; i++) 
            merged.push_back(nums2[i]);

        sort(merged.begin(), merged.end());

        int total = merged.size();

        if(total % 2 == 1) 
            return static_cast<double>(merged[total / 2]);
        else {
            int middle1 = merged[total / 2 - 1];
            int middle2 = merged[total / 2];
            return (static_cast<double>(middle1) + static_cast<double>(middle2)) / 2.0;
        }
    }
};

// Better Approach - Two Pointer Technique
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int i = 0, j = 0, first = 0, second = 0;

        int cnt = 0;
        while(i < n && j < m && cnt <= (n + m) >> 1) {
            first = second;
            if(nums1[i] < nums2[j]) {
                second = nums1[i];
                i++;
            }
            else {
                second = nums2[j];
                j++;
            }
            cnt++;
        }
        while(i < n && cnt <= (n + m) >> 1) {
            first = second;
            second = nums1[i];
            i++;
            cnt++;
        }
        while(j < m && cnt <= (n + m) >> 1) {
            first = second;
            second = nums2[j];
            j++;
            cnt++;
        }

        if((n + m) % 2 == 1) 
            return static_cast<double>(second);
        else {
            double ans = static_cast<double>(first) + static_cast<double>(second);
            return ans / 2.0;
        }
    }
};

// Optimal Approach - Binary Search
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