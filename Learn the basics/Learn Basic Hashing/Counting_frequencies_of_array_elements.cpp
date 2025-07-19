// https://www.geeksforgeeks.org/problems/frequency-of-array-elements-1587115620/1

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void frequencyCount(vector<int>& arr, int N, int P) {
        int* a = new int[N];
        for(int i = 0; i < N; i++)
            arr[i] = 0;
        for(int i = 0; i < N; i++) {
            if(arr[i] > N)
                continue;
            a[arr[i] - 1]++;
        }
        for(int i = 0; i < N; i++) {
            arr[i] = a[i];
        }
        return;
    }
};
