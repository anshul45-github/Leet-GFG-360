// https://leetcode.com/problems/kth-largest-element-in-an-array/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, less<int>> pq(nums.begin(), nums.end());
        for(int i = 0; i < k - 1; i++) {
            pq.pop();
        }
        return pq.top();
    }
};
