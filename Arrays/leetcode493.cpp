#include<bits/stdc++.h>
using namespace std;

class Solution {
    void merge(vector<int>& nums, int l, int mid, int r, int& inversions) {
        int i = l;
        int j = mid + 1;
        int idx = 0;
        int* a = new int[r - l + 1];
        for(int t1 = l; t1 <= mid; t1++) {
            int t2 = mid + 1;
            while(t2 <= r && nums[t1] > 2 * (long)nums[t2])
                t2++;
            inversions += t2 - (mid + 1);
        }
        while(i <= mid && j <= r) {
            if(nums[i] <= nums[j]) {
                a[idx] = nums[i];
                i++;
                idx++;
            }
            else {
                a[idx] = nums[j];
                j++;
                idx++;
            }
        }
        while(i <= mid) {
            a[idx] = nums[i];
            i++;
            idx++;
        }
        while(j <= r) {
            a[idx] = nums[j];
            j++;
            idx++;
        }
        for(int i = l; i <= r; i++)
            nums[i] = a[i - l];
        return;
    }
    void mergeSort(vector<int>& nums, int l, int r, int& inversions) {
        if(l >= r)
            return;
        int mid = l + (r - l) / 2;
        mergeSort(nums, l, mid, inversions);
        mergeSort(nums, mid + 1, r, inversions);
        merge(nums, l, mid, r, inversions);
    }
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        int reversedPairs = 0;
        mergeSort(nums, 0, n - 1, reversedPairs);
        return reversedPairs;
    }
};
