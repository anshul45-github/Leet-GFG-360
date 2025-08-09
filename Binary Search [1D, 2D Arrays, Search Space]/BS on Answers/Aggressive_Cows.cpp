// https://www.geeksforgeeks.org/problems/aggressive-cows/1

#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool isValid(vector<int>& stalls, int k, int minDistance) {
        // cout << minDistance << endl;
        int left = 0;
        for(int right = 0; right < stalls.size(); right++) {
            // cout << left << " " << right << endl;
            if(stalls[right] - stalls[left] >= minDistance) {
                k--;
                left = right;
            }
        }
        // cout << endl;
        return k <= 1;
    }
  public:
    int aggressiveCows(vector<int> &stalls, int k) {
        sort(stalls.begin(), stalls.end());
        int low = 0, high = stalls.back() - stalls[0];
        int ans = 0;
        // cout << low << " " << high << endl;
        while(low <= high) {
            int mid = low + ((high - low) >> 1);
            if(isValid(stalls, k, mid)) {
                ans = mid;
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
        return ans;
    }
};