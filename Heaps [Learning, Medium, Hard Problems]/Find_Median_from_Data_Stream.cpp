// https://leetcode.com/problems/find-median-from-data-stream/

#include<bits/stdc++.h>
using namespace std;

// Approach 1 - Brute Force (Sorting) - TLE
class MedianFinder {
private:
    vector<int> arr;

public:
    MedianFinder() {
        // No initialization needed for vector, it's done automatically
    }

    void addNum(int num) {      // O(1)
        arr.push_back(num);
    }

    double findMedian() {       // O(n log n) due to sorting
        sort(arr.begin(), arr.end());
        int size = arr.size();
        if(size % 2 == 0) 
            return (arr[size / 2 - 1] + arr[size / 2]) / 2.0;
        else 
            return arr[size / 2];
    }
};

// Approach 2 - Using Binary Search
class MedianFinder {
private:
    vector<int> arr;
public:
    MedianFinder() {
        // No initialization needed for vector, it's done automatically
    }

    void addNum(int num) {                      // O(n)
        // Binary search to find the correct position to insert
        int beg = 0;
        int end = arr.size();
        while(beg < end) {
            int mid = (end + beg) / 2;
            if(arr[mid] > num) 
                end = mid;
            else 
                beg = mid + 1;
        }
        arr.insert(arr.begin() + beg, num);
    }

    double findMedian() {                       // O(1)
        int n = arr.size();
        if(n % 2 == 1) 
            return arr[n / 2];
        else 
            return (arr[n / 2 - 1] + arr[n / 2]) / 2.0;
    }
};

// Approach 3 - Using Two Heaps
class MedianFinder {
    priority_queue<int> high;
    priority_queue<int> low;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {              // O(log n)
        low.push(num);
        high.push(-low.top());
        low.pop();
        if(low.size() < high.size()) {
            low.push(-high.top());
            high.pop();
        }
    }
    
    double findMedian() {               // O(1)
        if((high.size() + low.size()) & 1)
            return low.top();
        return (low.top() - high.top()) / (double)2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */