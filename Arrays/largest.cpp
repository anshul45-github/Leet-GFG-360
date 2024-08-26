#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int largest(vector<int> &arr) {
        int maxEl = arr[0];
        for(int i = 1; i < arr.size(); i++) {
            maxEl = max(maxEl, arr[i]);
        }
        return maxEl;
    }
};
