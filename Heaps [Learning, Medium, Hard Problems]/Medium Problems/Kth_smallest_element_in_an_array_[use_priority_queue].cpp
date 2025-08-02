// https://www.geeksforgeeks.org/problems/kth-smallest-element5635/1

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int kthSmallest(vector<int> &nums, int k) {
        priority_queue<int> pq;
        for(int i = 0; i < nums.size(); i++) {
            pq.push(nums[i]);
            while(pq.size() > k)
                pq.pop();
        }
        return pq.top();
    }
};