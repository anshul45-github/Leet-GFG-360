// https://www.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        int len = 0;
        unordered_map<int, int> mp;
        mp[0] = -1;
        int sum = 0;
        for(int i = 0; i < arr.size(); i++) {
            sum += arr[i];
            // cout << sum << " ";
            if(!mp.count(sum))
                mp[sum] = i;
            if(mp.count(sum - k))
                len = max(len, i - mp[sum - k]);
        }
        return len;
    }
};