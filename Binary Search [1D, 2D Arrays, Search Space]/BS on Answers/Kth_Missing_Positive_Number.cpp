// https://leetcode.com/problems/kth-missing-positive-number/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int low = 0, high = arr.size() - 1;
        int ceil = arr.size();
        while(low <= high) {
            int mid = low + ((high - low) >> 1);
            int missing = arr[mid] - mid - 1;
            if(missing < k)
                low = mid + 1;
            else {
                ceil = mid;
                high = mid - 1;
            }
        }
        if(ceil == arr.size()) {
            int missing = arr.back() - arr.size();
            return arr.back() - missing + k;
        }
        int missing = arr[ceil] - ceil - 1;
        return arr[ceil] - missing + k - 1;
    }
};