// https://leetcode.com/problems/reverse-pairs/description/
// 493. Reverse Pairs
// Hard

#include<bits/stdc++.h>
using namespace std;

class Solution {
    int pairs;
    void merge(vector<int>& nums, int l, int mid, int r) {
        int i = l;
        int j = mid + 1;
        int k = 0;
        while(i <= mid && j <= r) {
            int tempcnt = 0;
            while(j <= r && 1LL * nums[i] > 2LL * nums[j]) {
                tempcnt++;
                j++;
            }
            pairs += (mid - i + 1) * tempcnt;
            i++;
        }
        i = l;
        j = mid + 1;
        vector<int> temp(r - l + 1);
        while(i <= mid && j <= r) {
            if(nums[i] <= nums[j]) {
                temp[k] = nums[i];
                i++;
            }
            else if(nums[i] > nums[j]) {
                temp[k] = nums[j];
                j++;
            }
            k++;
        }
        while(i <= mid) {
            temp[k] = nums[i];
            i++;
            k++;
        }
        while(j <= r) {
            temp[k] = nums[j];
            j++;
            k++;
        }
        for(k = l; k <= r; k++)
            nums[k] = temp[k - l];
    }
    void mergeSort(vector<int>& nums, int l, int r) {
        if(l >= r)
            return;
        int mid = l + ((r - l) >> 1);
        mergeSort(nums, l, mid);
        mergeSort(nums, mid + 1, r);
        merge(nums, l, mid, r);
    }
public:
    int reversePairs(vector<int>& nums) {
        pairs = 0;
        mergeSort(nums, 0, nums.size() - 1);
        return pairs;
    }
};