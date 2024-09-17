#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int* a = new int[m + n];
        int i = 0;
        int j = 0;
        int idx = 0;
        while(i < m && j < n) {
            if(nums1[i] < nums2[j]) {
                a[idx] = nums1[i];
                i++;
            }
            else {
                a[idx] = nums2[j];
                j++;
            }
            idx++;
        }
        while(i < m) {
            a[idx++] = nums1[i++];
        }
        while(j < n) {
            a[idx++] = nums2[j++];
        }
        for(i = 0; i < m + n; i++)
            nums1[i] = a[i];
        return;
    }
};
