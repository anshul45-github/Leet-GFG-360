// https://leetcode.com/problems/hand-of-straights/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize)
            return false;
        priority_queue<int, vector<int>, greater<int>> pq(hand.begin(), hand.end());
        while(!pq.empty()) {
            vector<int> tmp;
            int i = 1;
            int prev = pq.top();
            pq.pop();
            while(!pq.empty()) {
                if(i == groupSize)
                    break;
                int k = pq.top();
                if(k > prev + 1)
                    return false;
                if(prev + 1 == k) {
                    i++;
                    prev++;
                }
                else {
                    tmp.push_back(k);
                }
                pq.pop();
            }
            if(i != groupSize)
                return false;
            for(int i : tmp)
                pq.push(i);
        }
        return true;
    }
};
