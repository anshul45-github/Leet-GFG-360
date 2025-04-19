// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/description/
// // 1011. Capacity To Ship Packages Within D Days

#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool isPossible(vector<int>& weights, int capacity, int days) {
        int d = 0;
        for(int i = 0; i < weights.size();) {
            int sum = 0;
            while(i < weights.size() && sum + weights[i] <= capacity) {
                sum += weights[i];
                i++;
            }
            d++;
        }
        return d <= days;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int r = weights[0];
        int l = weights[0];
        for(int i = 1; i < weights.size(); i++) {
            r += weights[i];
            l = max(l, weights[i]);
        }
        while(l < r) {
            int mid = l + ((r - l) >> 1);
            if(isPossible(weights, mid, days))
                r = mid;
            else
                l = mid + 1;
        }
        return r;
    }
};