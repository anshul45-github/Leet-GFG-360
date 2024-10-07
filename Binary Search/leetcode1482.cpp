#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool isPossible(vector<int> bloomDay, int days, int m, int k, int n) {
        for(int i = 0; i < n; i++)
            bloomDay[i] -= days;
        int c = 0;
        for(int i = 0; i < n; i++) {
            if(bloomDay[i] <= 0)
                c++;
            else
                c = 0;
            if(c == k) {
                m--;
                c = 0;
            }
        }
        return m <= 0;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        // long long t = m * k;
        // if((long long)(m * k) > n)
        //     return -1;
        int l = INT_MAX;
        int h = INT_MIN;
        for(int i = 0; i < n; i++) {
            l = min(l, bloomDay[i]);
            h = max(h, bloomDay[i]);
        }
        int x = h + 1;
        int minDays = h + 1;
        while(l <= h) {
            int mid = l + ((h - l) >> 1);
            if(isPossible(bloomDay, mid, m, k, n)) {
                minDays = mid;
                h = mid - 1;
            }
            else
                l = mid + 1;
        }
        if(minDays == x)
            return -1;
        return minDays;
    }
};
