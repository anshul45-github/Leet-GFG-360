// https://www.geeksforgeeks.org/problems/does-array-represent-heap4345/1

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    bool isMaxHeap(int arr[], int N)
    {
        for(int i = 0; i < N / 2; i++) {
            int left = (2 * i) + 1;
            int right = left + 1;
            if(arr[i] < arr[left])
                return false;
            else if(right < N && arr[i] < arr[right])
                return false;
        }
        return true;
    }
};
