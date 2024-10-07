#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool isPossible(vector<int> weights, int capacity, int days, int n) {
        int dayCount = 1;
        int c = capacity;
        for(int i = 0; i < n; i++) {
            if(weights[i] <= c) {
                c -= weights[i];
            }
            else {
                dayCount++;
                c = capacity;
                c -= weights[i];
            }
        }
        return dayCount <= days;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int l = INT_MIN;
        int h = 0;
        for(int i = 0; i < n; i++) {
            l = max(l, weights[i]);
            h += weights[i];
        }
        int minDays = h;
        while(l <= h) {
            int mid = l + ((h - l) >> 1);
            if(isPossible(weights, mid, days, n)) {
                minDays = mid;
                h = mid - 1;
            }
            else
                l = mid + 1;
        }
        return minDays;
    }
};
