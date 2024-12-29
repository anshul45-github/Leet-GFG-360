#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // arr : given array
    // k : find kth smallest element and return using this function
    int kthSmallest(vector<int> &arr, int k) {
        priority_queue<int, vector<int>, greater<int>> pq(arr.begin(), arr.end());
        for(int i = 0; i < k - 1; i++)
            pq.pop();
        return pq.top();
    }
};
