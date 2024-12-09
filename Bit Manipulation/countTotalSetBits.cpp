// TC : O(N), SC : O(logN)
#include<bits/stdc++.h>
using namespace std;

class Solution{
    int solve(int n, vector<int>& dp) {
        if(dp[n] != -1)
            return dp[n];
        dp[n] = solve(n >> 1, dp) + (n & 1);
        return dp[n];
    }
    public:
    int countSetBits(int n) {
        if(n == 0)
            return 0;
        
        int cnt = 0;
        
        int x = 1;
        int power = 0;
        while((x << 1) <= n) {
            x = x << 1;
            power++;
        }
        cnt += power * x / 2;
        cnt += n - x + 1;
        cnt += countSetBits(n - x);
        return cnt;
    }
};
