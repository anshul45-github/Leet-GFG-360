// https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool isValid(vector<int>& bloomDay, int m, int k, int day) {
        int left = 0;
        for(int right = 0; right < bloomDay.size(); right++) {
            if(bloomDay[right] > day) 
                left = right + 1;
            if(right - left + 1 == k) {
                m--;
                left = right + 1;
            }
        }
        return m <= 0;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if(1LL * m * k > bloomDay.size())
            return -1;
        int low = 1, high = bloomDay[0];
        for(int x : bloomDay)
            high = max(high, x);
        int ans = high;
        while(low <= high) {
            int mid = low + ((high - low) >> 1);
            if(isValid(bloomDay, m, k, mid)) {
                ans = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        return ans;
    }
};