// https://www.geeksforgeeks.org/problems/merge-sort/1

#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    void merge(int arr[], int l, int m, int r)
    {
        int i = l;
        int j = m + 1;
        int idx = 0;
        int* temp = new int[r - l + 1];
        while(i <= m && j <= r) {
            if(arr[i] <= arr[j]) {
                temp[idx++] = arr[i++];
            }
            else {
                temp[idx++] = arr[j++];
            }
        }
        while(i <= m) {
            temp[idx++] = arr[i++];
        }
        while(j <= r) {
            temp[idx++] = arr[j++];
        }
        for(i = 0, j = l; j <= r; i++, j++)
            arr[j] = temp[i];
    }
    public:
    void mergeSort(int arr[], int l, int r)
    {
        if(l >= r)
            return;
        int mid = l + (r - l) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }
};
