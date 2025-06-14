// https://leetcode.com/problems/kth-largest-element-in-a-stream/
// Easy

// Design a class to find the kth largest element in a stream. Note that it is the kth largest element in the sorted order, not the kth distinct element.

// Implement KthLargest class:
// KthLargest(int k, int[] nums) Initializes the object with the integer k and the stream of integers nums.
// int add(int val) Appends the integer val to the stream and returns the element representing the kth largest element in the stream.

// Example 1:
// Input
// ["KthLargest", "add", "add", "add", "add", "add"]
// [[3, [4, 5, 8, 2]], [3], [5], [10], [9], [4]]
// Output
// [null, 4, 5, 5, 8, 8]
// Explanation
// KthLargest kthLargest = new KthLargest(3, [4, 5, 8, 2]);
// kthLargest.add(3); // returns 4
// kthLargest.add(5); // returns 5
// kthLargest.add(10); // returns 5
// kthLargest.add(9); // returns 8
// kthLargest.add(4); // returns 8

// Constraints:
// 0 <= nums.length <= 10^4
// -10^4 <= nums[i] <= 10^4
// At most 10^4 calls will be made to add.

// Approach: Use a min-heap to keep track of the k largest elements. The top of the heap will be the kth largest element.

#include<bits/stdc++.h>
using namespace std;

class KthLargest {
    int k;
    vector<int> nums;
    priority_queue<int, vector<int>, greater<int>> pq;
public:
    KthLargest(int k, vector<int>& nums) {
        this -> k = k;
        for(int i = 0; i < nums.size(); i++)
            pq.push(nums[i]);
        while(pq.size() > k)
            pq.pop();
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size() > k)
            pq.pop();
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */