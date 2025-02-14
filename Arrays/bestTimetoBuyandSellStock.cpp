#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> cummin;
        int minVal = prices[0];
        cummin.push_back(minVal);
        int n = prices.size();
        for(int i = 1; i < n; i++) {
            minVal = min(minVal, prices[i]);
            cummin.push_back(minVal);
        }
        int maxProfit = 0;
        for(int i = 1; i < n; i++) {
            maxProfit = max(prices[i] - cummin[i], maxProfit);
        }
        return maxProfit;
    }
};
