// https://www.geeksforgeeks.org/problems/find-minimum-and-maximum-element-in-an-array4428/1

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    pair<int, int> getMinMax(vector<int> arr) {
        int maxi = INT_MIN;
        int mini = INT_MAX;
        for(int x : arr) {
            maxi = max(maxi, x);
            mini = min(mini, x);
        }
        return {mini, maxi};
    }
};