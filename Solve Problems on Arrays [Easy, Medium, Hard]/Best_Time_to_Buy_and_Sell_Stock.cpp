// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minTillNow = prices[0];
        int maxProfit = 0;
        for(int i = 1; i < prices.size(); i++) {
            int profit = prices[i] - minTillNow;
            maxProfit = max(profit, maxProfit);
            minTillNow = min(minTillNow, prices[i]);
        }
        return maxProfit;
    }
};