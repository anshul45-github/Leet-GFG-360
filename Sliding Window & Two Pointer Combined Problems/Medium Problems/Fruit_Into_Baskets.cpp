// https://www.geeksforgeeks.org/problems/fruit-into-baskets-1663137462/1

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int totalElements(vector<int> &arr) {
        unordered_map<int, int> mp;
        int d = 0;
        int l = 0;
        int r = 0;
        int maxlen = 0;
        while(r < arr.size()) {
            mp[arr[r]]++;
            if(mp[arr[r]] == 1)
                d++;
            while(d > 2) {
                mp[arr[l]]--;
                if(mp[arr[l]] == 0)
                    d--;
                l++;
            }
            maxlen = max(maxlen, r - l + 1);
            r++;
        }
        return maxlen;
    }
};