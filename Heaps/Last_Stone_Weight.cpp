// https://leetcode.com/problems/last-stone-weight/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int, vector<int>, less<int>> pq;
        for(int i = 0; i < stones.size(); i++)
            pq.push(stones[i]);
        while(pq.size() > 1) {
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            if(a != b) {
                a = a - b;
                pq.push(a);
            }
        }
        return pq.size() ? pq.top() : 0;
    }
};