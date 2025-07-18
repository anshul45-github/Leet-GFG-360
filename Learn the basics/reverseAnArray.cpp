#include<bits/stdc++.h>
using namespace std;

class Solution {
    void recur(vector<int>& arr, int i, int j) {
        if(i >= j)
            return;
        swap(arr[i], arr[j]);
        recur(arr, i + 1, j - 1);
    }
  public:
    void reverseArray(vector<int> &arr) {
        recur(arr, 0, arr.size() - 1);
        return;
    }
};
