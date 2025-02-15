#include <bits/stdc++.h> 
using namespace std;

long long merge(long long* arr, int l, int mid, int r) {
    int i = l;
    int j = mid + 1;
    int idx = 0;
    long long inversions = 0;
    vector<long long> temp;
    while(i <= mid && j <= r) {
        if(arr[i] <= arr[j]) {
            temp.push_back(arr[i]);
            i++;
        }
        else {
            temp.push_back(arr[j]);
            j++;
            inversions += 1LL * (mid - i + 1);
        }
    }
    while(i <= mid) {
        temp.push_back(arr[i]);
        i++;
    }
    while(j <= r) {
        temp.push_back(arr[j]);
        j++;
    }
    for(int i = l; i <= r; i++) {
        arr[i] = temp[i - l];
    }
    return inversions;
}

long long mergeSort(long long* arr, int l, int r) {
    if(l >= r)
        return 0;
    int mid = l + ((r - l) >> 1);
    long long inversions = 0;
    inversions += mergeSort(arr, l, mid);
    inversions += mergeSort(arr, mid + 1, r);
    inversions += merge(arr, l, mid, r);
    return inversions;
}

long long getInversions(long long *arr, int n){
    return mergeSort(arr, 0, n - 1);
}