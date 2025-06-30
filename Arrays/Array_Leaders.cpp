// https://www.geeksforgeeks.org/problems/leaders-in-an-array-1587115620/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> leaders(vector<int>& arr) {
        vector<int> ans;
        int maxi = -1;
        for(int i = arr.size() - 1; i >= 0; i--) {
            if(arr[i] >= maxi)
                ans.push_back(arr[i]);
            maxi = max(maxi, arr[i]);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};