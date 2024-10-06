#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool isPossible(vector<int>& piles, int k, int h, int n) {
        long long time = 0;
        for(int i = 0; i < n; i++) {
            time += piles[i] % k == 0 ? piles[i] / k : piles[i] / k + 1;
        }
        return time <= h;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int l = 1;
        // int r = n - 1;
        int minK = INT_MIN;
        for(int i = 0; i < n; i++) {
            minK = max(piles[i], minK);
        }
        int r = minK;
        while(l <= r) {
            int mid = l + (r - l) / 2;
            if(isPossible(piles, mid, h, n)) {
                minK = mid;
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
        return minK;
    }
};
