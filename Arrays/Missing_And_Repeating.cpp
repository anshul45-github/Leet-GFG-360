// https://www.geeksforgeeks.org/problems/find-missing-and-repeating2512/1

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        int repeating = 0;
        int missing = 0;
        int n = arr.size();
        for(int i = 0; i < n; i++) {
            int idx = abs(arr[i]) - 1;
            if(arr[idx] < 0)
                repeating = abs(arr[i]);
            else
                arr[idx] = -arr[idx];
        }
        for(int i = 0; i < n; i++) {
            if(arr[i] > 0) {
                missing = i + 1;
                break;
            }
        }
        return {repeating, missing};
    }
};
