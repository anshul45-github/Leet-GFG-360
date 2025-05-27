// https://leetcode.com/problems/permutation-sequence/
// Hard

// Given two integers n and k, return the kth permutation sequence of the numbers from 1 to n.

// Example 1:
// Input: n = 3, k = 3
// Output: "213"
// Explanation: The permutations are ["123","132","213","231","312","321"], and the 3rd permutation is "213".

// Example 2:
// Input: n = 4, k = 9
// Output: "2314"

// Example 3:
// Input: n = 3, k = 1
// Output: "123"

// Constraints:
// 1 <= n <= 9
// 1 <= k <= n! (factorial of n)

// Note: The solution uses a precomputed factorial array to determine the position of each digit in the permutation sequence.

// The algorithm iteratively selects the next digit based on the value of k and the remaining digits, adjusting k accordingly until all digits are selected.

// Time Complexity: O(n^2) due to the vector erase operation.
// Space Complexity: O(n) for storing the digits in a vector.

#include<vector>
#include<string>
#include<cmath>
using namespace std;

class Solution {
    vector<int> facts = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
public:
    string getPermutation(int n, int k) {
        string ans = "";
        vector<char> nums;
        for(int i = 0; i < n; i++)
            nums.push_back('1' + i);
        while(n) {
            int c = facts[n] / n;
            int s = ceil((double)k / c);
            ans += nums[s - 1];
            nums.erase(nums.begin() + s - 1);
            k = k % c;
            if(k == 0)
                k = c;
            n--;
        }
        return ans;
    }
};