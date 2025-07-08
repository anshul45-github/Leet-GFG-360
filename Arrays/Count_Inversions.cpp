// https://www.geeksforgeeks.org/problems/inversion-of-array-1587115620/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
    int ans;
    void merge(vector<int>& arr, int l, int mid, int r) {
        int i = l;
        int j = mid + 1;
        int k = 0;
        vector<int> temp(r - l + 1);
        while(i <= mid && j <= r) {
            if(arr[i] <= arr[j]) {
                temp[k] = arr[i];
                i++;
            }
            else {
                ans += mid - i + 1;
                temp[k] = arr[j];
                j++;
            }
            k++;
        }
        while(i <= mid) {
            temp[k] = arr[i];
            i++;
            k++;
        }
        while(j <= r) {
            temp[k] = arr[j];
            j++;
            k++;
        }
        for(i = l; i <= r; i++)
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
    int inversionCount(vector<int> &arr) {
        ans = 0;
        mergeSort(arr, 0, arr.size() - 1);
        return ans;
    }
};