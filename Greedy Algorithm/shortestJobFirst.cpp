// TC : O(nlogn), SC : O(1)
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    long long solve(vector<int>& bt) {
        sort(bt.begin(), bt.end());
        int temp = 0;
        int ans = 0;
        for(int i = 0; i < bt.size(); i++) {
            ans += temp;
            temp += bt[i];
        }
        return ans / bt.size();
    }
};
