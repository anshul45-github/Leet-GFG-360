// https://www.geeksforgeeks.org/problems/merge-k-sorted-arrays/1

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        for(int i = 0; i < arr.size(); i++)
            pq.push({arr[i][0], i, 0});
        vector<int> ans;
        while(!pq.empty()) {
            auto v = pq.top();
            pq.pop();
            ans.push_back(v[0]);
            if(v[2] != K - 1)
                pq.push({arr[v[1]][v[2] + 1], v[1], v[2] + 1});
        }
        return ans;
    }
};