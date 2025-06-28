// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = INT_MAX;
        int maxProfit = 0;
        for(int i = 0; i < prices.size(); i++) {
            mini = min(mini, prices[i]);
            maxProfit = max(maxProfit, prices[i] - mini);
        }
        return maxProfit;
    }
};