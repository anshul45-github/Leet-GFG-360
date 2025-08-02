#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i = 0; i < K; i++) {
            for(int j = 0; j < K; j++) {
                pq.push(arr[i][j]);
            }
        }
        vector<int> v;
        while(!pq.empty()) {
            v.push_back(pq.top());
            pq.pop();
        }
        return v;
    }
};
