// https://leetcode.com/problems/find-two-non-overlapping-sub-arrays-each-with-target-sum/
// Medium

// Given an array of integers arr and an integer target, return the minimum sum of lengths of two non-overlapping sub-arrays that sum to target.

// If no such sub-arrays exist, return -1.

// A sub-array is a contiguous part of an array.

// Example 1:
// Input: arr = [3,2,2,4,3], target = 3
// Output: 2
// Explanation: The two sub-arrays are [3] and [3].
// The minimum sum of lengths is 1 + 1 = 2.

// Example 2:
// Input: arr = [7,3,4,7], target = 7
// Output: 2
// Explanation: The two sub-arrays are [7] and [7].
// The minimum sum of lengths is 1 + 1 = 2.

// Example 3:
// Input: arr = [4,3,2,6,2,3,4], target = 6
// Output: -1
// Explanation: There are no two sub-arrays that sum to 6.

// Constraints:
// 1 <= arr.length <= 10^5
// 1 <= arr[i] <= 1000
// 1 <= target <= 10^8

// Note: The solution uses a sliding window approach to find the minimum sum of lengths of two non-overlapping sub-arrays that sum to the target.

// The algorithm maintains two pointers to track the start and end of the current sub-array, and uses two vectors to store the minimum lengths of sub-arrays found so far.

// The solution iterates through the array, updating the pointers and lengths as it finds valid sub-arrays that sum to the target.

// The final result is computed by checking the minimum lengths stored in the vectors and returning the sum of the two lengths if valid sub-arrays are found.

#include<vector>
#include<climits>
using namespace std;

class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int l = 0;
        int sum = 0;
        vector<int> pre(arr.size() + 1, 1e9);
        vector<int> suf(arr.size(), 1e9);
        for(int r = 0; r < arr.size(); r++) {
            sum += arr[r];
            while(sum > target) {
                sum -= arr[l];
                l++;
            }
            if(sum == target) {
                pre[r + 1] = r - l + 1;
                suf[l] = r - l + 1;
            }
        }
        for(int i = 1; i < arr.size() + 1; i++) 
            pre[i] = min(pre[i - 1], pre[i]);
        for(int i = arr.size() - 2; i >= 0; i--)
            suf[i] = min(suf[i + 1], suf[i]);
        int ans = INT_MAX;
        for(int i = 0; i < arr.size(); i++) {
            if(pre[i] == 1e9 || suf[i] == 1e9)
                continue;
            ans = min(ans, pre[i] + suf[i]);
        }
        if(ans == INT_MAX)
            return -1;
        return ans;
    }
};