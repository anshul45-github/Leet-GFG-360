// https://www.geeksforgeeks.org/problems/longest-bitonic-subsequence0824/1

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int LongestBitonicSequence(int n, vector<int> &arr) {
        vector<int> increasing(n, 1);
        int incMax = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(arr[i] > arr[j] && increasing[j] + 1 > increasing[i]) 
                    increasing[i] = increasing[j] + 1;
            }
            if(increasing[i] > incMax) 
                incMax = increasing[i];
        }
        vector<int> decreasing(n, 1);
        int decMax = 0;
        for(int i = n - 1; i >= 0; i--) {
            for(int j = n - 1; j > i; j--) {
                if(arr[i] > arr[j] && decreasing[j] + 1 > decreasing[i]) 
                    decreasing[i] = decreasing[j] + 1;
            }
            if(decreasing[i] > decMax) 
                decMax = decreasing[i];
        }
        int ans = 0;
        for(int i = 1; i < n - 1; i++) {
            if(increasing[i] > 1 && decreasing[i] > 1)
                ans = max(ans, increasing[i] + decreasing[i] - 1);
        }
        return ans;
    }
};