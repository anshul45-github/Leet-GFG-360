// https://leetcode.com/problems/koko-eating-bananas/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool isPossible(vector<int>& piles, int h, int k) {
        long long time = 0;
        for(int i = 0; i < piles.size(); i++) {
            time += piles[i] / k;
            if(piles[i] % k)
                time++;
        }
        return time <= h;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = piles[0];
        for(int i = 1; i < piles.size(); i++)
            r = max(r, piles[i]);
        while(l < r) {
            int mid = l + ((r - l) >> 1);
            if(isPossible(piles, h, mid))
                r = mid;
            else
                l = mid + 1;
        }
        return r;
    }
};