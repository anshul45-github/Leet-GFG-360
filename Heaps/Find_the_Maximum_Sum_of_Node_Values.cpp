// https://leetcode.com/problems/find-the-maximum-sum-of-node-values/

#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        priority_queue<int> pq;
        for(int i = 0; i < nums.size(); i++) 
            pq.push((nums[i] ^ k) - nums[i]);
        long long sum = 0;
        while(pq.size() && pq.top() > 0) {
            int u = pq.top();
            pq.pop();
            if(pq.size() == 0)
                break;
            int v = pq.top();
            pq.pop();
            if(u + v >= 0)
                sum += 1LL * u + v;
            else
                break;
        }
        for(int i = 0; i < nums.size(); i++)
            sum += 1LL * nums[i];
        return sum;
    }
};