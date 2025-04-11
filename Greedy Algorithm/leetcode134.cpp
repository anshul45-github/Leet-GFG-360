// Problem Name - Gas Station
// Sheet - Neetcode 150
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas = 0;
        int totalCost = 0;
        for(int i = 0; i < gas.size(); i++) {
            totalGas += gas[i];
            totalCost += cost[i];
        }
        if(totalCost > totalGas)
            return -1;
        int start = 0;
        int surplus = 0;
        for(int i = 0; i < gas.size(); i++) {
            surplus += gas[i] - cost[i];
            if(surplus < 0) {
                surplus = 0;
                start = i + 1;
            }
        }
        return start;
    }
};
