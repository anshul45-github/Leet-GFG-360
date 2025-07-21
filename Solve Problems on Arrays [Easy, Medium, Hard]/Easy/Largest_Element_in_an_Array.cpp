// https://www.geeksforgeeks.org/problems/largest-element-in-array4009/1

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int largest(vector<int> &arr) {
        int maxi = INT_MIN;
        for(int x : arr)
            maxi = max(maxi, x);
        return maxi;
    }
};