// https://leetcode.com/problems/find-median-from-data-stream/

#include<bits/stdc++.h>
using namespace std;

class MedianFinder {
    priority_queue<int> small, large;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        small.push(num);
        large.push(-small.top());
        small.pop();
        if(small.size() < large.size()) {
            small.push(-large.top());
            large.pop();
        }
    }
    
    double findMedian() {
        if(small.size() == large.size())
            return ((double)small.top() - (double)large.top()) / 2.0;
        return small.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */