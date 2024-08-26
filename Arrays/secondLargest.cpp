#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int print2largest(vector<int> &arr) {
        int maxEl = arr[0];
        for(int i = 1; i < arr.size(); i++)
            maxEl = max(arr[i], maxEl);
        int secondMax = 0;
        for(int i = 0; i < arr.size(); i++) {
            if(arr[i] != maxEl)
                secondMax = max(arr[i], secondMax);
        }
        if(secondMax)
            return secondMax;
        return -1;
    }
};
