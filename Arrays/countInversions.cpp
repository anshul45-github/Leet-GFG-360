#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void merge(vector<long long> &arr, int l, int mid, int r, long long int& inversions) {
        int i = l;
        int j = mid + 1;
        int k = 0;
        int *a = new int[r - l + 1];
        while(i <= mid && j <= r) {
            if(arr[i] <= arr[j]) {
                a[k] = arr[i];
                i++;
            }
            else {
                a[k] = arr[j];
                j++;
                inversions += mid - i + 1;
            }
            k++;
        }
        while(i <= mid)
            a[k++] = arr[i++];
        while(j <= r)
            a[k++] = arr[j++];
        for(int i = 0; i <= r - l; i++)
            arr[i + l] = a[i];
        return;
    }
    void mergeSort(vector<long long> &arr, int l, int r, long long int& inversions) {
        if(l >= r)
            return;
        int mid = l + (r - l) / 2;
        mergeSort(arr, l, mid, inversions);
        mergeSort(arr, mid + 1, r, inversions);
        merge(arr, l, mid, r, inversions);
        return;
    }
    long long int inversionCount(vector<long long> &arr) {
        long long int inversions = 0;
        mergeSort(arr, 0, arr.size() - 1, inversions);
        return inversions;
    }
};
