// https://www.geeksforgeeks.org/problems/egg-dropping-puzzle-1587115620/1

#include<bits/stdc++.h>
using namespace std;

class Solution {
    int getMinimumFloor(int floors, int eggs, vector<vector<int>>& dp) {
        if(floors == 0 || floors == 1) 
            return floors;
        if(eggs == 1)
            return floors;
        if(dp[eggs][floors] != -1)
            return dp[eggs][floors];
        int ans = 1e9;
        int start = 1, end = floors;
        while(start <= end) {
            int mid = start + ((end - start) >> 1);
            int getsBreaked = getMinimumFloor(mid - 1, eggs - 1, dp); 
            int remainSafe = getMinimumFloor(floors - mid, eggs, dp);
            int temp_ans = 1 + max(remainSafe, getsBreaked);
            if(getsBreaked > remainSafe)
                end = mid - 1;
            else
                start = mid + 1;
            ans = min(ans, temp_ans);
        }
        return dp[eggs][floors] = ans;
    }
public:
    int eggDrop(int e, int f) {
        vector<vector<int>> dp(e + 1, vector<int>(f + 1, -1));
        return getMinimumFloor(f, e, dp);
    }
};