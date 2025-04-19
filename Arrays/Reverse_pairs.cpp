// https://leetcode.com/problems/reverse-pairs/description/
// 493. Reverse Pairs
// Hard

#include<bits/stdc++.h>
using namespace std;

class Solution {
    void merge(vector<int>& nums, int l, int mid, int r, int& cnt) {
        int i = l;
        int j = mid + 1;
        int k = 0;
        int tempCnt = 0;
        while(i <= mid && j <= r) {
            while(j <= r && 1LL * nums[i] > 2LL * nums[j]) {
                j++;
                tempCnt++;
            }
            cnt += (mid - i + 1) * tempCnt;
            tempCnt = 0;
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
            else {
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
        for(i = l; i <= r; i++)
            nums[i] = temp[i - l];
    }
    void mergeSort(vector<int>& nums, int l, int r, int& cnt) {
        if(l >= r)
            return;
        int mid = l + ((r - l) >> 1);
        mergeSort(nums, l, mid, cnt);
        mergeSort(nums, mid + 1, r, cnt);
        merge(nums, l, mid, r, cnt);
    }
public:
    int reversePairs(vector<int>& nums) {
        int cnt = 0;
        mergeSort(nums, 0, nums.size() - 1, cnt);
        return cnt;
    }
};