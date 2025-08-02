// https://www.geeksforgeeks.org/problems/nearly-sorted-1587115620/1

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void nearlySorted(vector<int>& arr, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i = 0; i <= k; i++)
            pq.push(arr[i]);
        int i = k + 1;
        while(!pq.empty()) {
            int u = pq.top();
            pq.pop();
            arr[i - k - 1] = u;
            if(i < arr.size())
                pq.push(arr[i]);
            i++;
        }
    }
};