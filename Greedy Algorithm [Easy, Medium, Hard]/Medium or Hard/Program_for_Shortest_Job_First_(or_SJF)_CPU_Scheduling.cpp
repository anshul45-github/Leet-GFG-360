// https://www.geeksforgeeks.org/problems/shortest-job-first/1

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    long long solve(vector<int>& bt) {
        sort(bt.begin(), bt.end());
        long long ans = 0;
        long long sum = 0;
        for(int i = 0; i < bt.size() - 1; i++) {
            sum += bt[i];
            ans += sum;
        }
        return ans / bt.size();
    }
};