#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int select(int arr[], int i, int N)
    {
        int minIdx = i;
        for(int j = i + 1; j < N; j++) {
            if(arr[j] < arr[minIdx])
                minIdx = j;
        }
        return minIdx;
    }
    void selectionSort(int arr[], int n)
    {
        for(int i = 0; i < n; i++) {
            int minEl = select(arr, i, n);
            swap(arr[minEl], arr[i]);
        }
        return;
    }
};
