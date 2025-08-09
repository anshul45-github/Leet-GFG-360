// https://www.geeksforgeeks.org/problems/ceil-the-floor2802/1

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> getFloorAndCeil(int x, vector<int> &arr) {
        vector<int> v = {INT_MIN, INT_MAX};
        for(int i = 0; i < arr.size(); i++) {
            if(arr[i] <= x) {
                v[0] = max(v[0], arr[i]);
            }
            if(arr[i] >= x) {
                v[1] = min(v[1], arr[i]);
            }
        }
        if(v[0] == INT_MIN)
            v[0] = -1;
        if(v[1] == INT_MAX)
            v[1] = -1;
        return v;
    }
};
