// https://leetcode.com/problems/partition-array-into-three-parts-with-equal-sum/
// Easy

// Given an array of integers arr, return true if we can partition the array into three non-empty parts with equal sums.

// Formally, we can partition the array if we can find indexes i + 1 < j with (arr[0] + arr[1] + ... + arr[i] == arr[i + 1] + arr[i + 2] + ... + arr[j - 1] == arr[j] + arr[j + 1] + ... + arr[arr.length - 1])

// Example 1:
// Input: arr = [0,2,1,-6,6,-7,9,1,2,0,1]
// Output: true
// Explanation: 0 + 2 + 1 = 3, -6 + 6 -7 + 9 + 1 = 3, 2 + 0 + 1 = 3. All parts have equal sums of 3.

// Example 2:
// Input: arr = [0,2,1,-6,6,7,9,-1,2,0,1]
// Output: false
// Explanation: You cannot partition the array into three parts with equal sums.

// Example 3:
// Input: arr = [3,3,6,5,-2,2,5,1,-9,4]
// Output: true
// Explanation: 3 + 3 = 6, 6 = 6, 5 - 2 + 2 + 5 + 1 - 9 + 4 = 6. All parts have equal sums of 6.

// Constraints:
// 3 <= arr.length <= 5 * 10^4
// -10^4 <= arr[i] <= 10^4

// Time Complexity: O(n)
// Space Complexity: O(1)

// This code checks if an array can be partitioned into three parts with equal sums.

// It calculates the total sum of the array, checks if it is divisible by 3, and then iterates through the array to find the partitions.

#include<vector>
using namespace std;

class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int sum = 0;
        for(int x : arr)
            sum += x;
        if(sum % 3)
            return false;
        int n = sum / 3;
        int tempSum = 0;
        int cnt = 0;
        for(int i = 0; i < arr.size(); i++) {
            tempSum += arr[i];
            if(tempSum == n) {
                tempSum = 0;
                cnt++;
                if(cnt == 3) {
                    for(int j = i + 1; j < arr.size(); j++)
                        tempSum += arr[j];
                    if(tempSum != 0)
                        return false;
                    else
                        return true;
                }
            }
        }
        return false;
    }
};