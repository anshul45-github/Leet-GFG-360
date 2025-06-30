// https://leetcode.com/problems/reverse-pairs/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    int ans;
    void merge(vector<int>& arr, int l, int mid, int r) {
        int j = mid + 1;
        for (int i = l; i <= mid; ++i) {
            while (j <= r && 1LL * arr[i] > 2LL * arr[j])
                j++;
            ans += j - (mid + 1);
        }
        vector<int> temp(r - l + 1);
        int i = l, k = 0;
        j = mid + 1;
        while(i <= mid && j <= r) {
            if(arr[i] <= arr[j])
                temp[k++] = arr[i++];
            else
                temp[k++] = arr[j++];
        }
        while(i <= mid) temp[k++] = arr[i++];
        while(j <= r) temp[k++] = arr[j++];
        for(i = l; i <= r; ++i)
            arr[i] = temp[i - l];
    }
    void mergeSort(vector<int>& arr, int l, int r) {
        if(l >= r)
            return;
        int mid = l + ((r - l) >> 1);
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }
public:
    int reversePairs(vector<int>& arr) {
        ans = 0;
        mergeSort(arr, 0, arr.size() - 1);
        return ans;
    }
};