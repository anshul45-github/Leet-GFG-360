// https://leetcode.com/problems/find-k-closest-elements/
// Medium

// Given a sorted array arr, two integers k and x, return the k closest integers to x in the array. The result should also be sorted in ascending order. 

// An integer a is closer to x than an integer b if:
// |a - x| < |b - x|, or |a - x| == |b - x| and a < b.

// Example 1:
// Input: arr = [1,2,3,4,5], k = 4, x = 3
// Output: [1,2,3,4]
// Explanation: The four closest integers to 3 are [1,2,3,4], which are returned in ascending order.

// Example 2:
// Input: arr = [1,2,3,4,5], k = 4, x = -1
// Output: [1,2,3,4]
// Explanation: The four closest integers to -1 are [1,2,3,4], which are returned in ascending order.

#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int l = 0;
        int r = arr.size() - 1;
        while(r - l + 1 > k) {
            if(abs(arr[l] - x) <= abs(arr[r] - x))
                r--;
            else
                l++;
        }
        vector<int> ans(arr.begin() + l, arr.begin() + r + 1);
        return ans;
    }
};