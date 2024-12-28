#include<bits/stdc++.h>
using namespace std;

class Solution {
    void heapify(vector<int>& arr, int n, int i) {
        int largest = i;
        int l = (2 * i) + 1;
        int r = (2 * i) + 2;
        if(l < n && arr[largest] < arr[l])
            largest = l;
        if(r < n && arr[largest] < arr[r])
            largest = r;
        if(largest != i) {
            swap(arr[largest], arr[i]);
            heapify(arr, n, largest);
        }
    }
public:
    void convertMinToMaxHeap(vector<int> &arr, int N) {
        for(int i = N / 2; i >= 0; i--) {
            heapify(arr, N, i);
        }
    }
    
};
